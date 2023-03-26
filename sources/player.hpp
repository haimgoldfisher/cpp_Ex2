#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{
    class Player
    {
        string name;
        int stackSize = 0; // the size of the deck of the player
        int cardsTaken = 0; // I guess its the number of the cards the player won during battles

        public:
        Player(); // default constructer
        Player(string newName); // according to the Demo file
        int stacksize(); // public 'get' method for stackSize
        int cardesTaken(); // public 'get' method for cardsTaken
        string getName(); // public 'get' method for Player's name
    };
}

#endif