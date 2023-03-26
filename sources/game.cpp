#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "game.hpp"
#include "player.hpp"

namespace ariel
{
    Game::Game(Player& pl1, Player& pl2) : player1(pl1), player2(pl2) // references to the players, so the game will modify their arrtibutes
    {
        // intialize decks.... game stats... 
    }

    void Game::playTurn()
    {
        return;
    }

    void Game::printLastTurn()
    {
        return;
    }

    void Game::playAll()
    {
        return;
    }

    void Game::printWiner()
    {
        return;
    }

    void Game::printLog()
    {
        return;
    }

    void Game::printStats()
    {
        return;
    }
}
