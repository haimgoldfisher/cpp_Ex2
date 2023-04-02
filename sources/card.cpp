#include "card.hpp"

namespace ariel
{
    Card::Card(int number, Suit symbol)
    {
        if(number > KING || number < 1)
        {
            throw("ILLEGAL NUMBER");
            exception;
        }
        if(symbol < CLUBS || symbol > SPADES)
        {
            throw("ILLEGAL SUIT");
            exception;
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
