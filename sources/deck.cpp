#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <algorithm>
using namespace std;

#include "deck.hpp"

namespace ariel
{
    Deck::Deck(bool complete)
    {
        if (complete) // flag for empty or full deck
        {
            for (int i = 1; i <= 4; i++) // {EMPTY = 0, CLUBS = 1, DIAMONDS = 2, HEARTS = 3, SPADES = 4}
            {
                Suit suit = (Suit)i;
                for (int val = 2; val <= ACE; val++) // 2 to 14
                {
                    Card newCard(val, suit);
                    this->stack.push_back(newCard);
                }
            }
        }
    }

    bool Deck::isEmpty()
    {
        return this->stack.empty();
    }
    
    void Deck::shuffle(int amount)
    {
        srand(time(0)); // random seed
        for (int i = 0; i < amount; i++)
        {
            random_shuffle(this->stack.begin(), this->stack.end()); // build-in shuffle function (<algorithm>)
        }
    }

    Card Deck::drawCard()
    {
        Card top = this->stack[static_cast<unsigned long>(this->getSize()-1)]; // make a copy of the card
        this->stack.pop_back(); // pop the original card from the deck
        return top;
    }
    
    void Deck::passCard(Deck& other)
    {
        Card toInsert = this->drawCard(); // draw a card from the deck
        other.stack.push_back(toInsert); // put it in the other deck
    }

    int Deck::getSize()
    {
        return this->stack.size();
    }
}