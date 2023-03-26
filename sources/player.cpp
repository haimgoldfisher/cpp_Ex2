#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "player.hpp"

namespace ariel
{
    Player::Player()
    {
        this->name = "Unknown Player";
    }

    Player::Player(string newName)
    {
        this->name = newName;
    }

    int Player::stacksize()
    {
        return this->stackSize;
    }
    int Player::cardesTaken()
    {
        return this->cardsTaken;
    }
    string Player::getName()
    {
        return this->name;
    }
}