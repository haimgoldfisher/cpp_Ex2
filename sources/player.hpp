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
        int wins = 0;
        int loses = 0;
        int draws = 0;

        public:
        Player(); // default constructer
        Player(string newName); // according to the Demo file
        int stacksize(); // public 'get' method for stackSize
        int cardesTaken(); // public 'get' method for cardsTaken
        void setTaken(int add); // public 'set' method for cardsTaken
        string getName(); // public 'get' method for Player's name
        void startGame(); // playing setter
        void endGame(); // playing setter
        bool isInGame(); // it checks if the player is still in a game
        void addWin(); // it adds a win to wins counter
        void addLose(); // it adds a lose to loses counter
        void addTie(); // it adds a tie to draws counter
        int getWins();
        int getLoses();
        int getTies();
        void dropCard(); // it decreases stackSize by one
    };
}

#endif