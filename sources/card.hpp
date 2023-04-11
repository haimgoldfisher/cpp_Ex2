#ifndef CARD_H
#define CARD_H

typedef enum {EMPTY = 0, CLUBS = 1, DIAMONDS = 2, HEARTS = 3, SPADES = 4} Suit; // symbols for cards
// special cards:
constexpr int JACK = 11;
constexpr int QUEEN = 12;
constexpr int KING = 13;
constexpr int ACE = 14;

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
        Card(int, Suit); // it creates a card with number and suit
        int getValue(); // it returns the value of the card
        Suit getSuit(); // it returns the suit (symbol) of the card (♠/♥/♣/♦)
        string getValAsStr(); // it returns the value of the card as a string
        string getSuitAsStr(); // it returns the suit of the card as a string
    };
}

#endif