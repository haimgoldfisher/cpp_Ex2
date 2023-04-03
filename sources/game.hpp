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
#include "deck.hpp"
using namespace ariel;

namespace ariel
{
    class Game
    {
        Player& player1;
        Player& player2;
        Deck deckP1 = Deck(false); 
        Deck deckP2 = Deck(false);
        bool finish = false;

        public:
        Game(Player& pl1, Player& pl2); // references to selected players
        void playTurn(); // let us play a single battle
        void printLastTurn(); // let us prints the result of the last game that was played
        void playAll(); // let us run the whole game 
        void printWiner(); // let us print the name of the winner (during the game or only after the game was played?)
        void printLog(); // let us print the chain of moves in the game (during the game or only after the game was played?)
        void printStats(); // let us print win rate, cards won, other stats...
                           // Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws.)
    };
}

#endif