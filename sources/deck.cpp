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
            this->stack.reserve(52); // since we need only 52 cards
            for (int i = 1; i <= 4; i++) // {EMPTY = 0, CLUBS = 1, DIAMONDS = 2, HEARTS = 3, SPADES = 4}
            {
                Suit suit = (Suit)i;
                for (int val = 2; val <= ACE; val++) // 2 to 14
                {
                    this->stack.emplace_back(val, suit); // insert every card using Card ctor into it's place
                }
            }
            stack.shrink_to_fit(); // since we need only 52 cards - no more adding
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
            random_shuffle(this->stack.begin(), this->stack.end()); // build-in shuffle function (<algorithm>) - using build-in Vector's Iterator
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
        other.stack.emplace_back(this->drawCard()); // draw the card from this deck and pass it to other deck
    }

    int Deck::getSize()
    {
        return this->stack.size();
    }
}