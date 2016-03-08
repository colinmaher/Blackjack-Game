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
    int p = 0;
    string n;
    int high = 0;

    do{
    cout << "How many players? : ";
    cin >> p;
    if(p > 8) cout << "8 players maximum." << endl;
    }while(p > 8);

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

      if(players[i].hand.getScore() == 21)
          cout << "Blackjack!" << endl;

      while(choice != "N" && choice != "n" && players[i].hand.getScore() < 21){
        cout << "Hit? [Y/N]: ";
        cin >> choice;

        if(choice == "Y" || choice == "y"){
          players[i].hand.addCard(deck.drawCard());
          cout << players[i].getName() << " : ";
          players[i].hand.print();

          if(players[i].hand.getScore() > 21)
            cout << "Bust!" << endl;
        }

        if(players[i].hand.getScore() == 21)
          cout << "Blackjack!";
      }

      if(players[i].hand.getScore() > high && players[i].hand.getScore() <= 21){
        high = players[i].hand.getScore();
        n = players[i].getName();
      }

      if(players[i].hand.getScore() == high && n != players[i].getName()){
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