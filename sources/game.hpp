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
        Player& player1; // player 1 reference
        Player& player2; // player 2 reference
        string winner; // it holds the name of the the winner of the game (when its over)
        Deck deckP1 = Deck(false); // empty deck for player 1
        Deck deckP2 = Deck(false); // empty deck for player 2
        bool finish = false; // flag that changes when the game is over
        vector<string> gameLog; // it saves the string of each turn

        public:
        Game(Player&, Player&); // references to selected players
        void playTurn(); // let us play a single battle
        void printLastTurn(); // let us prints the result of the last game that was played
        void playAll(); // let us run the whole game 
        void printWiner(); // let us print the name of the winner (during the game or only after the game was played?)
        void printLog(); // let us print the chain of moves in the game (during the game or only after the game was played?)
        void printStats(); // let us print win rate, cards won, other stats...
                           // Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws.)
        void closeGame(); // it calls the winner and free the players from the game
        void battle(int, string, string); // the cards that the winner win, name of the winner & battle's chain of events
    };
}

#endif