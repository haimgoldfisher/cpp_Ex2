#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "game.hpp"
#include "player.hpp"

namespace ariel
{
    Game::Game(ariel::Player p1, ariel::Player p2)
    {
        this->player1 = p1;
        this->player2 = p2;
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
