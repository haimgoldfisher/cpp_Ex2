#ifndef DECK_H
#define DECK_H

#include "card.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;

namespace ariel
{
    class Deck
    {
        vector<Card> stack; // the deck

        public:
        Deck(bool); // it creates a disired stack of cards (full \ empty)
        bool isEmpty(); // it returns true if the deck has no cards left
        void shuffle(int); // its shuffle the deck with a disired number of iters
        Card drawCard(); // it draws the top card of a deck and returns it
        void passCard(Deck&); // it takes the top card of a deck and move it to another deck
        int getSize(); // public 'get' method for the size of the deck
    };
}

#endif