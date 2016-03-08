#include <iostream>
#include <string>
using namespace std;
#ifndef CARD_H
#define CARD_H

template< typename T > class Deck;                            

//this class defines a card with a suit and a value
template< typename T >
class Card 
{
  friend class Deck< T >;

public:
  Card( T v, T s ) : value( v ), suit(s){} 
  T getValue() const{ 
    return value; 
  }

  T getSuit() const{
    return suit;
  }

  string toString() const{
    string card = getValueString() + getSuitString();
    return card;
  }

  string getValueString() const{
    string str;

  switch(value){
    case 1:
      str = "A";
      break;
    case 2:
      str = "2";
      break;
    case 3:
      str = "3";
      break;
    case 4:
      str = "4";
      break;
    case 5:
      str = "5";
      break;
    case 6:
      str = "6";
      break;
    case 7:
      str = "7";
      break;
    case 8:
      str = "8";
      break;
    case 9:
      str = "9";
      break;
    case 10:
      str = "T";
      break;
    case 11:
      str = "J";
      break;
    case 12:
      str = "Q";
      break;
    case 13:
      str = "K";
      break;
    default:
      return "";
    }
   return str;
  }

  string getSuitString() const{
    string s;

    switch(suit){
    case 0:
      s = "C";
      break;
    case 1:
      s = "D";
      break;
    case 2:
      s = "H";
      break;
    case 3:
      s = "S";
      break;
    default:
      return "";
    }
    return s;
  }

private:
  T value;
  T suit;
}; 
#endif