#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "player.hpp"
using namespace ariel;

Player::Player(string newName = "Unknown Player")
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