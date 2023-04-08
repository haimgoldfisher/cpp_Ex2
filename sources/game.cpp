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
        Deck deck(true); // full deck
        deck.shuffle(10); // shuffle the deck 10 times
        while(!deck.isEmpty())
        {
            deck.passCard(this->deckP1);
            deck.passCard(this->deckP2);
        }
        pl1.startGame();
        pl2.startGame();
    }

    void Game::closeGame()
    {
        if (player1.cardesTaken() > player2.cardesTaken())
        {
            this->winner = player1.getName();
        }
        else
        {
            this->winner = player2.getName();
        }
        this->player1.endGame();
        this->player2.endGame();
    }

    void Game::playTurn()
    {
        if (&player1 == &player2)
        {
            throw runtime_error("A PLAYER CANNOT PLAY AGAINST ITSELF");
        }
        if (!this->player1.isInGame() || !this->player2.isInGame())
        {
            throw runtime_error("GAME ALREADY ENDED");
        }
        string battleWinner, battleLog;
        battleLog = "";
        Deck treasureDeck(false); // the winner will get this deck's cards
        battle(treasureDeck, battleLog, battleWinner);
        if (this->player1.stacksize() == 0 || this->player1.stacksize() == 0)
        {
            this->closeGame();
        }
    }

    void Game::battle(Deck& prizeDeck, string battleWinner, string battleLog)
    {
        if (this->player1.stacksize() == 0 || this->player1.stacksize() == 0)
        {
            battleLog += "Run out of cards.";
            if(!prizeDeck.isEmpty())
            {
                player1.setTaken(prizeDeck.getSize()/2);
                player2.setTaken(prizeDeck.getSize()/2);
            }
            return;
        }
        Card p1card = this->deckP1.drawCard();
        Card p2card = this->deckP2.drawCard();
        this->player1.dropCard();
        this->player2.dropCard();
        prizeDeck.insertToDeck(p1card).insertToDeck(p2card);
        string p1 = p1card.getValAsStr() + " of " + p1card.getSuitAsStr();
        string p2 = p2card.getValAsStr() + " of " + p2card.getSuitAsStr();
        battleLog = this->player1.getName()+" played "+p1+" "+this->player2.getName()+ " played "+p2+". ";
        if (p1card.getValue() > p2card.getValue())
        {
            if (p1card.getValue() == ACE && p2card.getValue() == 2)
            {
                player2.setTaken(2); // only 2 wins ACE
                battleWinner = player2.getName();
                this->player2.addWin();
                this->player1.addLose();
            }
            else
            {
                player1.setTaken(2);
                battleWinner = player1.getName();
                this->player1.addWin();
                this->player2.addLose();
            }
        }
        else if (p1card.getValue() < p2card.getValue())
        {
            if (p2card.getValue() == ACE && p1card.getValue() == 2)
            {
                player1.setTaken(2); // only 2 wins ACE
                battleWinner = player1.getName();
                this->player1.addWin();
                this->player2.addLose();
            }
            else
            {
                player2.setTaken(2);
                battleWinner = player2.getName();
                this->player2.addWin();
                this->player1.addLose();
            }
        }
        else // TIE CASE
        {
            battleLog += "Draw. ";
            this->player1.addTie();
            this->player2.addTie();
            if (this->player1.stacksize() == 0 || this->player1.stacksize() == 0) // if cant place one more hidden card
            {
                battleLog += "Run out of cards.";
                player1.setTaken(prizeDeck.getSize()/2);
                player2.setTaken(prizeDeck.getSize()/2);
                return;
            }
            Card p1card2 = this->deckP1.drawCard(); // place one hidden card
            Card p2card2 = this->deckP2.drawCard(); // place one hidden card
            this->player1.dropCard();
            this->player2.dropCard();
            prizeDeck.insertToDeck(p1card2).insertToDeck(p2card2);
            battle(prizeDeck, battleLog, battleWinner);
        }
        battleLog += battleWinner+" wins."; // name of winner
    }

    void Game::printLastTurn()
    {
        if(this->player1.cardesTaken() == 0 && this->player2.cardesTaken() == 0)
        {
            throw runtime_error("THE FIRST TURN DID NOT PLAY");
        }
        string toPrint = this->gameLog.at(this->gameLog.size()-1);
        cout << toPrint << endl;
    }

    void Game::playAll()
    {
        while(this->player1.isInGame())
        {
            playTurn();
        }
    }

    void Game::printWiner()
    {
        if(!this->finish)
        {
            throw runtime_error("GAME IS STILL IN PROGRESS");
        }
        cout << this->winner << endl;
    }

    void Game::printLog()
    {
        if(this->player1.cardesTaken() == 0 && this->player2.cardesTaken() == 0)
        {
            throw runtime_error("THE FIRST TURN DID NOT PLAY");
        }
        for (int i = 0; i < this->gameLog.size(); i++)
        cout << this->gameLog[static_cast<unsigned long>(i)] << endl;
    }

    void Game::printStats()
    {
        string pl1 = this->player1.getName() + " Stats: Total wins: "+to_string(this->player1.getWins())+
        ", Total Loses: "+to_string(this->player1.getLoses())+", Total Ties:"+to_string(this->player1.getTies())+".";
        string pl2 = this->player2.getName() + " Stats: Total wins: "+to_string(this->player2.getWins())+
        ", Total Loses: "+to_string(this->player2.getLoses())+", Total Ties:"+to_string(this->player2.getTies())+".";
        cout << pl1 << endl;
        cout << pl2 << endl;
    }
}
