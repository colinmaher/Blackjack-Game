#include <iostream>
#include <string>
#include "deck.h"
using namespace std;
#ifndef PLAYER_H
#define PLAYER_H
//this class is used to create a player object with a name and hand
template<typename T>
class Player{
public:
  Player(string n){
    name = n;
  }

  Deck<T> getHand(){
    return hand;
  }

  string getName(){
    return name;
  }

  string name;
  Deck<T> hand;
  Deck<T> split;
};

#endif