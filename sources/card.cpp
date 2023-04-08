#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "card.hpp"

namespace ariel
{
    Card::Card() // empty card
    {
        this->value = 0;
        this->suit = EMPTY;
    }

    Card::Card(int number, Suit symbol)
    {
        if(number > ACE || number < 2)
        {
            throw runtime_error("ILLEGAL NUMBER");
        }
        if(symbol < CLUBS || symbol > SPADES)
        {
            throw runtime_error("ILLEGAL SUIT");
        }
        this->value = number;
        this->suit = symbol;
    }

    int Card::getValue()
    {
        return this->value;
    }

    Suit Card::getSuit()
    {
        return this->suit;
    }

    string Card::getValAsStr()
    {
         switch (this->getValue())
            {
            case JACK:
                return "Jack";
            
            case QUEEN:
                return "Queen";
            
            case KING:
                return "King";
            
            case ACE:
                return "Ace";
            
            default: // 2-10
                return std::to_string(this->getValue());
            }
    }
    string Card::getSuitAsStr()
    {
        switch (this->getSuit())
            {
            case HEARTS:
                return "Hearts";
            
            case DIAMONDS:
                return "Diamonds";
            
            case CLUBS:
                return "Clubs";
            
            case SPADES:
                return "Spades";
            
            default:
                throw runtime_error("ILLEGAL SUIT");
            }
    }
}
