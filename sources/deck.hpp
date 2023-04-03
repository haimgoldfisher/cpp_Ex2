#ifndef DECK_H
#define DECK_H

#include "card.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{
    class Deck
    {
        int cardsNum; // the number of cards in the deck
        Card* stack; // the deck

        public:
        Deck(bool complete); // it creates an empty deck (complete or empty)
        ~Deck(); // destructor
        bool isEmpty(); // return true if the deck has no cards left
        bool shuffle(); // its shuffle the deck
        bool insertToDeck(Card c); // it insert a specific card to a deck
        Card top(); // it shows the top card of the deck
        void PlayCard(); // it takes the the top card from the deck and play a turn with it
    };
}

#endif