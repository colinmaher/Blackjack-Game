#include <iostream>
#include <string>
#include <cstdio>
#include "game.h"

using namespace std;

int main(){ 
  string choice = "";

  do{
    Game<int> game;
    game.play();
    cout << "Play again? [Y/N]: ";
    cin >> choice;
  }while(choice == "Y" || choice == "y");
	cout << "\nThanks for playing!";
	cin.clear();
    cin.ignore(10000,'\n');
	getchar();
}