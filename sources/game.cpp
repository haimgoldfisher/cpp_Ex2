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
        if (pl1.isInGame() || pl2.isInGame())
        {
            throw runtime_error("ONE OR TWO PLAYERS ARE STILL IN A GAME");
        }
        Player* pl1ptr = &pl1;
        Player* pl2ptr = &pl2;
        if (pl1ptr == pl2ptr) // both points to the same object
        {
            throw runtime_error("A PLAYER CANNOT PLAY AGAINST ITSELF");
        }
        Deck deck(true);
        deck.shuffle();
        while(!deck.isEmpty())
        {
            deck.share(this->deckP1);
            deck.share(this->deckP2);
        }
        // playing -> true;

    }

    void Game::playTurn()
    {
        if (this->deckP1.isEmpty() || this->deckP2.isEmpty())
        {
            throw runtime_error("DECK OUT OF CARDS");
        }
        
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
