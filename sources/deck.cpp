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
        srand(time(0));
        for (int i = 0; i < amount; i++)
        {
            random_shuffle(this->stack.begin(), this->stack.end());
        }
    }

    Card Deck::drawCard()
    {
        Card drawed = this->stack[static_cast<unsigned long>(this->getSize()-1)];
        this->stack.pop_back();
        return drawed;
    }
    
    void Deck::passCard(Deck& other)
    {
        Card toInsert = this->drawCard();
        other.stack.push_back(toInsert);
    }

    int Deck::getSize()
    {
        return this->stack.size();
    }
}