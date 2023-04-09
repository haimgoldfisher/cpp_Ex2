#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;

#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
using namespace ariel;

namespace ariel
{
    class Game
    {
        Player& player1;
        Player& player2;
        string winner;
        vector<Card> deckP1; // empty deck with 26 capacity 
        vector<Card> deckP2; // empty deck with 26 capacity 
        bool finish = false;
        vector<string> gameLog;

        public:
        Game(Player& pl1, Player& pl2); // references to selected players
        void playTurn(); // let us play a single battle
        void printLastTurn(); // let us prints the result of the last game that was played
        void playAll(); // let us run the whole game 
        void printWiner(); // let us print the name of the winner (during the game or only after the game was played?)
        void printLog(); // let us print the chain of moves in the game (during the game or only after the game was played?)
        void printStats(); // let us print win rate, cards won, other stats...
                           // Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws.)
        void closeGame(); // it calls the winner and free the players from the game
        void battle(int prize, string battleWinner, string battleLog); // recursive function that apply a single battle
    };
}

#endif