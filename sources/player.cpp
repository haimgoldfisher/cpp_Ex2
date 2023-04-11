#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
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
        this->addCardsWon(add);
    }
    void Player::setStack(int num)
    {
        this->stackSize = num;
    }
    string Player::getName()
    {
        return this->name;
    }
    void Player::startGame()
    {
        if (isInGame())
        {
            throw runtime_error("ALREADY PLAYING");
        }
        this->playing = true;
        this->wins = 0;
        this->loses = 0;
        this-> draws = 0;
        this->cardsWon = 0;
        this->turnsPlayed = 0;
        this->drawsMade = 0;
    }
    void Player::endGame()
    {
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

    void Player::addCard()
    {
        if (this->stacksize() > 25)
        {
            throw runtime_error("CANNOT ADD A CARD, THE STACK IS FULL");
        }
        this->stackSize++;
    }

    void Player::dropCard()
    {
        if (this->stacksize() < 1)
        {
            throw runtime_error("CANNOT DROP A CARD, THE STACK IS EMPTY");
        }
        this->stackSize--;
        this->AdddrawsMade(); // update that the player made a draw of a card
    }
    int Player::getCardsWon()
    {
        return this->cardsWon;
    }
    void Player::addCardsWon(int cardsNum)
    {
        this->cardsWon += cardsNum;
    }
    void Player::AdddrawsMade()
    {
        this->drawsMade++;
    }
    void Player::AddturnsPlayed()
    {
        this->turnsPlayed++;
    }
    int Player::getDrawsMade()
    {
        return this->drawsMade;
    }
    int Player::getTurnsPlayed()
    {
        return this->turnsPlayed;
    }
    float myRound(double num)
    {
        return round(num * 100.0) / 100.0;
    }

    string Player::rates()
    {
        double sum = this->wins + this->loses +this->draws;
        string winRate = to_string((this->wins/sum)*100);
        winRate = winRate.substr(0,5) + "%";
        string loseRate = to_string((this->loses/sum)*100)+"%"; 
        loseRate = loseRate.substr(0,5) + "%";
        string tieRate = to_string((this->draws/sum)*100)+"%";
        tieRate = tieRate.substr(0,5) + "%";
        return ". Win Rate: "+winRate+", Lose Rate: "+loseRate+", Draw Rate: "+tieRate+", ";
    }
}