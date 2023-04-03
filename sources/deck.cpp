#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "deck.hpp"

namespace ariel
{
    Deck::Deck(bool complete)
    {
        stack = new Card[52];
        if (!complete)
        {
            this->cardsNum = 0;
            for (int i = 0; i < 51; i++)
            {
                this->stack[i] = Card(); // empty card
            }
        }
        else
        {
            for (Suit suit = CLUBS; suit <= SPADES; suit++)
            {
                for (int val = ACE; val <= KING; val++)
                {
                    Card c(val, suit);
                    this->insertToDeck(c);
                }
            }
        }
    }

    Deck::~Deck()
    {
        delete[] stack;
    }

    bool Deck::isEmpty()
    {
        return this->cardsNum == 0;
    }
    bool Deck::shuffle()
    {

    }
    
    bool Deck::insertToDeck(Card c)
    {
        if (this->cardsNum == 52)
        {
            return false;
        }
        this->stack[52] = c;
        this->cardsNum++;
        return true;
    }
    Card Deck::top()
    {
        if (this->cardsNum == 0)
        {
            return Card();
        }
        return this->stack[cardsNum-1];
    }

    void Deck::PlayCard()
    {

    }
}