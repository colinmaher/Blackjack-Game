#include <iostream>
#include <string>
#include <vector>
#include "player.h"
using namespace std;
#ifndef GAME_H
#define GAME_H

//this class creates a random deck of cards, a vector of players, and contains the much of logic in running the game
template<typename T>
class Game{
public:
  Game(){
    deck.generateDeck();
  }

  void play(){
    int p;
    string n;
    int high = 0;
	
	cout << "How many players? : ";
	cin >> p;
    if(p > 8) cout << "8 players maximum." << endl;
	while(!cin){
		cin.clear();
		cin.ignore(10000,'\n');
		cout << "Invalid input." << endl;
		cout << "How many players? : ";
		cin >> p;
    }
	

    for(int i = 0; i<p; i++){
      cout << "Enter name of player " << i+1 << ": ";
      cin >> n;
      Player<T> *player = new Player<T>(n);
      players.push_back(*player);
    }

    deal(); 

    for(int i = 0; i<p; i++){
	  string choice = "";

	  cout << "\n" << players[i].getName() << " : "; 
	  players[i].hand.print();
	  cout << endl;

	  if(players[i].hand.getScore() == 21)
		  cout << "Blackjack!" << endl;

	  while(choice != "N" && choice != "n" && players[i].hand.getScore() < 21){
		if(players[i].hand.deck[0].getValue() == players[i].hand.deck[1].getValue()){
			cout << "Hit? [Y/N, S to split hand, H for help]: ";
			cin >> choice;
			if(choice == "S" || choice == "s"){
				players[i].split.addCard(&players[i].hand.deck[1]);
				players[i].hand.removeCard();
				players[i].hand.addCard(deck.drawCard());
				players[i].split.addCard(deck.drawCard());
				players[i].hand.print();
				cout << " | ";
				players[i].split.print();
				cout << endl;
			}
		}
		else{
			cout << "Hit? [Y/N, H for help]: ";
			cin >> choice;
		}
		if(choice == "Y" || choice == "y"){
			players[i].hand.addCard(deck.drawCard());
			cout << players[i].getName() << " : ";
			players[i].hand.print();
			cout << endl;

		  if(players[i].hand.getScore() > 21)
			cout << "Bust!" << endl;
		}
		else if(choice == "H" || choice == "h"){
			cout << "First character is card value, second is suit.\n"
			<< "D - Diamonds\nH - Hearts\nS - Spades\nC - Clubs\n" 
			<< "Aces are worth 1 or 11\n"
			<< "Splitting a pair allows you to play an additional hand" << endl; 
		}

		if(players[i].hand.getScore() == 21){
			cout << "Blackjack!";
		}
	  }
	  if(players[i].hand.getScore() > high && players[i].hand.getScore() <= 21){
		high = players[i].hand.getScore();
		n = players[i].getName();
	  }
	  if(!players[i].split.deck.empty()){
		choice = "";
		while(choice != "N" && choice != "n" && players[i].hand.getScore() != 21){
			cout << "(Split) Hit? [Y/N, H for help]: ";
			cin >> choice;
			if(choice == "Y" || choice == "y"){
			players[i].split.addCard(deck.drawCard());
			cout << players[i].getName() << " : ";
			players[i].split.print();
			cout << endl;

			if(players[i].split.getScore() > 21)
				cout << "Bust!" << endl;
			}
			else if(choice == "H" || choice == "h"){
				cout << "First character is card value, second is suit.\n"
				<< "D - Diamonds\nH - Hearts\nS - Spades\nC - Clubs\n" 
				<< "Aces are worth 1 or 11\n"
				<< "Splitting a pair allows you to play an additional hand" << endl; 
			}
			if(players[i].split.getScore() == 21){
				cout << "Blackjack!";
			}
		}
		if(players[i].split.getScore() > high && players[i].split.getScore() <= 21){
			high = players[i].split.getScore();
			n = players[i].getName();
		}
	}

	if((players[i].hand.getScore() == high || players[i].split.getScore()== high )&& n != players[i].getName()){
		n += " and " + players[i].getName();
	}
    } 
    cout << "\n" << n << " wins!" << endl;
  }

  void deal(){
    for(int i = 0; i<2; i++){
      for(unsigned int i = 0; i<players.size(); i++){
        players[i].hand.addCard(deck.drawCard());
      }
    }
  }

private:
  vector<Player<T>> players;
  Deck<T> deck;
};
#endif