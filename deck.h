#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "card.h"
using namespace std;
#ifndef DECK_H
#define DECK_H

template< typename T > class Player;

//this class contains the functions required to create and use a deck of cards
template<typename T>
class Deck{
  friend class Player<T>;

public:
  Deck(){
    srand((unsigned int)time(0));
  }

  void generateDeck(){
    for(int i = 1; i <= 13; i++){
      for(int j = 0; j <= 3; j++){
        Card<T> *c = new Card<T>(i,j);
        deck.push_back(*c);
      }
    }
    shuffleDeck();
  }

  void shuffleDeck(){
    random_shuffle(deck.begin(), deck.end());
  }

  void addCard(Card<T> *c){
    deck.push_back(*c);
  }

  Card<T>* drawCard(){
    if(!deck.empty()){
      Card<T>* card = &deck.back();
      deck.pop_back();
      return card;
    }
      return NULL;
  }

  void print() const{
    for(unsigned int i = 0; i < deck.size(); i++){
      cout << deck[i].toString() << " ";
    }
    cout << endl;
  }

  T getValue(Card<T> card) const{
    T value;
    if(card.getValueString() == "A")
      value = 11;
    else if(card.getValueString() == "2")
      value = 2;
    else if(card.getValueString() == "3")
      value = 3;
    else if(card.getValueString() == "4")
      value = 4;
    else if(card.getValueString() == "5")
      value = 5;
    else if(card.getValueString() == "6")
      value = 6;
    else if(card.getValueString() == "7")
      value = 7;
    else if(card.getValueString() == "8")
      value = 8;
    else if(card.getValueString() == "9")
      value = 9;
    else
      value = 10;
    return value;
  }

  T getScore() const{
    int numAces = 0;
    T total = 0;
    for(unsigned int i = 0; i < deck.size(); i++){
      if(deck[i].getValueString() == "A")
        numAces++;
      total += getValue(deck[i]);
    }
    if(total > 21 && numAces > 0)
      total -= 10*numAces;
    return total;
  }
  vector<Card<T>> getDeck(){
    return deck;
  }

private:
  vector<Card<T>> deck;
};
#endif