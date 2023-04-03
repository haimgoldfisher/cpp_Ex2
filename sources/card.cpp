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
        if(number > KING || number < 1)
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
}
