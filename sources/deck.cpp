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
        
        if (!complete)
        {
            this->cardsNum = 0;
        }
        else
        {
            for (int i = 1; i <= 4; i++) // {EMPTY = 0, CLUBS = 1, DIAMONDS = 2, HEARTS = 3, SPADES = 4}
            {
                Suit suit = (Suit)i;
                for (int val = 2; val <= ACE; val++)
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
        // return this->stack->empty();
    }
    Deck& Deck::shuffle(int amount)
    {
        srand(time(0));
        for (int i = 0; i < amount; i++)
        {
            int n = i + (rand() % (this->stack->size()-i)); // I took this shuffle method from https://www.geeksforgeeks.org/shuffle-a-deck-of-cards-3/
            swap(this->stack[i], this->stack[n]);
        }
    }
    
    Deck& Deck::insertToDeck(Card& c)
    {
        if (this->cardsNum == 52)
        {
             throw runtime_error("FULL DECK, CANNOT INSERT A CARD");
        }
        this->stack->push_back(c);
        this->cardsNum++;
        return *this;
    }
    Card& Deck::top()
    {
        if (this->cardsNum == 0)
        {
            throw runtime_error("EMPTY DECK");
        }
        return this->stack->at(cardsNum-1);
    }

    Card& Deck::drawCard()
    {
        if (this->isEmpty())
        {
            throw runtime_error("EMPTY DECK, CANNOT DRAW");
        }
        Card& out = this->stack->at(this->cardsNum-1);
        this->stack->pop_back();
        this->cardsNum--;
        return out;
    }

    Deck& Deck::passCard(Deck& other)
    {
        Card& toMove = this->drawCard();
        other.insertToDeck(toMove);
        return *this;
    }

    int Deck::getSize()
    {
        return this->cardsNum;
    }
}