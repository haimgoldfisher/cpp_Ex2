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
            for (int i = 1; i <= 4; i++) // {EMPTY = 0, CLUBS = 1, DIAMONDS = 2, HEARTS = 3, SPADES = 4}
            {
                Suit suit = (Suit)i;
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
    void Deck::shuffle(int amount)
    {
        srand(time(0));
        for (int i = 0; i < amount; i++)
        {
            int n = i + (rand() % (52 -i)); // I took this shuffle method from https://www.geeksforgeeks.org/shuffle-a-deck-of-cards-3/
            swap(this->stack[i], this->stack[n]);
        }
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

    Card Deck::drawCard()
    {
        if(this->isEmpty())
        {
            throw runtime_error("EMPTY DECK, CANNOT DRAW");
        }
        Card out = this->stack[this->cardsNum-1];
        this->stack[this->cardsNum-1] = Card();
        this->cardsNum--;
        return out;
    }

    void Deck::passCard(Deck other)
    {
        Card toMove = this->drawCard();
        other.insertToDeck(toMove);
    }
}