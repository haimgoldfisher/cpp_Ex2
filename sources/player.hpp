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
        int stackSize = 0; // the num of remained cards in the player's deck
        int cardsTaken = 0; // I guess its the number of the cards the player won during battles
        bool playing = false;

        public:
        Player(); // default constructer
        Player(string newName); // according to the Demo file
        int stacksize(); // public 'get' method for stackSize
        int cardesTaken(); // public 'get' method for cardsTaken
        string getName(); // public 'get' method for Player's name
        bool isInGame(); // it checks if the player is still in a game
    };
}

#endif