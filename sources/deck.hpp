#ifndef DECK_H
#define DECK_H

// typedef enum {PLAYER = 0, FULL_DECK = 1, EMPTY_DECK = 2} MODE; // modes for ctor

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
        int cardsNum; // the number of cards in the deck
        vector<Card>* stack = new vector<Card>;

        public:
        Deck(bool complete); // it creates a disired stack of cards (52 full \ 26 empty)
        ~Deck(); // destructor
        bool isEmpty(); // return true if the deck has no cards left
        Deck& shuffle(int amount); // its shuffle the deck with a disired times
        Deck& insertToDeck(Card& c); // it insert a specific card to a deck
        Card& top(); // it shows the top card of the deck
        Card& drawCard(); // it takes the top card of a deck and return it
        Deck& passCard(Deck& other); // it takes the top card of a deck and move it to another deck
        int getSize(); // cardsNum getter
    };
}

#endif