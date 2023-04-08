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
        this->name = "Unknown Player"; // im not sure if I want to allow this
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
    void Player::setTaken(int add)
    {
        this->cardsTaken += add;
    }
    string Player::getName()
    {
        return this->name;
    }
    void Player::startGame()
    {
        // if (isInGame())
        // {
        //     throw runtime_error("ALREADY PLAYING");
        // }
        this->playing = true;
    }
    void Player::endGame()
    {
        this->stackSize = 0;
        this->cardsTaken = 0;
        this->playing = false;
    }
    bool Player::isInGame()
    {
        return this->playing;
    }

    void Player::addWin()
    {
        this->wins++;
    }

    void Player::addLose()
    {
        this->loses++;
    }

    void Player::addTie()
    {
        this->draws++;
    }

    int Player::getWins()
    {
        return this->wins;
    }

    int Player::getLoses()
    {
        return this->loses;
    }

    int Player::getTies()
    {
        return this->draws;
    }

    void Player::dropCard()
    {
        if (this->stacksize() < 1)
        {
            throw runtime_error("CANNOT DROP A CARD, THE STACK IS EMPTY");
        }
        this->stackSize--;
    }
}