#ifndef CARD_H
#define CARD_H

typedef enum {EMPTY = -1, CLUBS = 0, DIAMONDS = 1, HEARTS = 2, SPADES = 3} Suit; // symbols for cards
// special cards:
constexpr int JACK = 11;
constexpr int QUEEN = 12;
constexpr int KING = 13;
constexpr int ACE = 1;

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{
    class Card
    {
        int value;
        Suit suit; // (♠/♥/♣/♦)

        public:
        Card(); // empty card
        Card(int number, Suit symbol); // it creates a card with number and suit
        int getValue(); // it returns the value of the card
        Suit getSuit(); // it returns the suit (symbol) of the card (♠/♥/♣/♦)
    };
}

#endif