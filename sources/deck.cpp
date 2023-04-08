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
        
        this->cardsNum = 0;
        if (complete)
        {
            for (int i = 1; i <= 4; i++) // {EMPTY = 0, CLUBS = 1, DIAMONDS = 2, HEARTS = 3, SPADES = 4}
            {
                Suit suit = (Suit)i;
                for (int val = 2; val <= ACE; val++) // 2 to 14
                {
                    Card newCard(val, suit);
                    this->insertToDeck(newCard);
                }
            }
        }
    }

    bool Deck::isEmpty()
    {
        return this->cardsNum == 0;
    }
    Deck& Deck::shuffle(int amount)
    {
        srand(time(0));
        std::random_shuffle(this->stack->begin(), this->stack->end());
        // for (int i = 0; i < amount; i++)
        // {
        //     int n = i + (rand() % (this->stack->size()-i)); // I took this shuffle method from https://www.geeksforgeeks.org/shuffle-a-deck-of-cards-3/
        //     swap(this->stack[i], this->stack[n]);
        // }
        return *this;
    }
    
    Deck& Deck::insertToDeck(Card& newCard)
    {
        if (this->cardsNum == 52)
        {
             throw runtime_error("FULL DECK, CANNOT INSERT A CARD");
        }
        this->stack->push_back(newCard);
        this->cardsNum++;
        return *this;
    }
    // Card& Deck::top()
    // {
    //     if (this->cardsNum == 0)
    //     {
    //         throw runtime_error("EMPTY DECK");
    //     }
    //     return this->stack->at(cardsNum-1);
    // }

    Card Deck::drawCard()
    {
        if (this->isEmpty())
        {
            throw runtime_error("EMPTY DECK, CANNOT DRAW");
        }
        Suit toDrawS = this->stack->at(static_cast<unsigned long>(cardsNum-1)).getSuit();
        int toDrawV = this->stack->at(static_cast<unsigned long>(cardsNum-1)).getValue();
        Card out(toDrawV, toDrawS);
        this->stack->pop_back();
        this->cardsNum--;
        return out;
    }

    Deck& Deck::passCard(Deck& other)
    {
        Card toMove = this->drawCard();
        other.insertToDeck(toMove);
        return *this;
    }

    int Deck::getSize()
    {
        return this->cardsNum;
    }
}