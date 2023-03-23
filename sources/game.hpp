#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
using namespace ariel;

namespace ariel
{
    class Game
    {
        Player player1;
        Player player2;

        public:

        Game(Player p1, Player p2); // outline

        void playTurn();

        void printLastTurn();

        void playAll();

        void printWiner();

        void printLog();

        void printStats();
    };
}

#endif