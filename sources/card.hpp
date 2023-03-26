#ifndef CARD_H
#define CARD_H

typedef enum {CLUBS = 0, DIAMONDS = 1, HEARTS = 2, SPADES = 3} Suit;
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
        // int value;
        // Suit symbol; // (♠/♥/♣/♦)

        // public:
        // Card(int number, Suit symbol); // it creates a card with number and suit
        // int getValue(); // it returns the value of the card
        // Suit getSuit(); // it returns the suit (symbol) of the card (♠/♥/♣/♦)
    };
}

#endif