#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "game.hpp"

namespace ariel
{
    Game::Game(Player& pl1, Player& pl2) : player1(pl1), player2(pl2) // references to the players, so the game will modify their attributes
    {
        if (!player1.isInGame() && !player2.isInGame()) // to make sure we dont destroy an exist game:
        {
            player1.setStack(26);
            player2.setStack(26);
            player1.initTaken();
            player2.initTaken();
        }
    }

    void Game::closeGame()
    {
        if (this->player1.cardesTaken() > this->player2.cardesTaken())
        {
            this->winner = player1.getName();
        }
        else if (player1.cardesTaken() < player2.cardesTaken())
        {
            this->winner = player2.getName();
        }
        else // when they both won 26 cards
        {
            this->winner = "Draw";
        }
        this->finish = true;
        this->player1.endGame();
        this->player2.endGame();
    }

    void Game::playTurn()
    {
        if (this->player1.stacksize() == 0 || this->player2.stacksize() == 0) // when try to play a turn after the game was closed
        {
            throw runtime_error("CANNOT PLAY A TURN, RUN OUT OF CARDS");
        }
        if (this->player1.cardesTaken() == 0 && this->player2.cardesTaken() == 0) // its the first turn
        {
            if (&this->player1 == &this->player2) // same player case
            {
                throw runtime_error("A PLAYER CANNOT PLAY AGAINST HIMSELF");
            }
            if (this->player1.isInGame() || this->player2.isInGame()) // when a player is already in another game
            {
                throw runtime_error("ONE OR MORE PLAYERS ARE ALREADY PLAYING");
            }
            Deck deck(true); // creates a complete deck with 52 cards
            deck.shuffle(5); // shuffle the deck 5 times
            while(!deck.isEmpty()) // deal a card to each player until they have 26 cards
            {
                deck.passCard(this->deckP1);
                deck.passCard(this->deckP2);
            }
            if (this->deckP1.getSize() != this->deckP1.getSize()) // self check that each player got the same amount of cards
            {
                throw runtime_error("UNEQUAL DISTRIBUTION");
            }
            this->player1.startGame(); 
            this->player2.startGame();
        }
        battle(0, "", ""); // a method for a turn's battle
        // update that both players made a turn:
        this->player1.AddturnsPlayed();
        this->player2.AddturnsPlayed();
        if (this->player1.cardesTaken() + this->player2.cardesTaken() == 52) // won all possible cards
        {
            closeGame();
        }
    }

    void Game::battle(int prize, string battleWinner, string battleLog)
    {
        while(true) // since a draw leads to another battle
        {
            if (this->player1.stacksize() == 0 || this->player1.stacksize() == 0) // someone run out of cards
            {
                battleLog += "Run out of cards.";
                if(prize != 0) // we need to share the cards between both players
                {
                    player1.setTaken(prize/2);
                    player2.setTaken(prize/2);
                }
                break;
            }
            Card p1card = this->deckP1.drawCard();
            Card p2card = this->deckP2.drawCard();
            this->player1.dropCard();
            this->player2.dropCard();
            prize += 2;
            string actionP1 = p1card.getValAsStr() + " of " + p1card.getSuitAsStr();
            string actionP2 = p2card.getValAsStr() + " of " + p2card.getSuitAsStr();
            battleLog += this->player1.getName() + " played "+ actionP1 +" "+ this->player2.getName()+  " played "+ actionP2 +". ";
            if (p1card.getValue() > p2card.getValue())
            {
                if (p1card.getValue() == ACE && p2card.getValue() == 2)
                {
                    this->player2.setTaken(prize); // only 2 wins ACE
                    battleWinner = player2.getName();
                    this->player2.addWin();
                    this->player1.addLose();
                }
                else
                {
                    this->player1.setTaken(prize);
                    battleWinner = player1.getName();
                    this->player1.addWin();
                    this->player2.addLose();
                }
                battleLog += battleWinner + " wins."; // name of winner
                break;
            }
            else if (p1card.getValue() < p2card.getValue())
            {
                if (p2card.getValue() == ACE && p1card.getValue() == 2)
                {
                    this->player1.setTaken(prize); // only 2 wins ACE
                    battleWinner = player1.getName();
                    this->player1.addWin();
                    this->player2.addLose();
                }
                else
                {
                    this->player2.setTaken(prize);
                    battleWinner = player2.getName();
                    this->player2.addWin();
                    this->player1.addLose();
                }
                battleLog += battleWinner + " wins."; // name of winner
                break;
            }
            else // TIE CASE
            {
                battleLog += "Draw. ";
                this->player1.addTie();
                this->player2.addTie();
                if (this->player1.stacksize() == 0 || this->player1.stacksize() == 0) // ran out of cards before nedd to place one hidden card
                {
                    battleLog += "Run out of cards."; // share the prize:
                    this->player1.setTaken(prize/2);
                    this->player2.setTaken(prize/2);
                    break;
                }
                Card p1card2 = this->deckP1.drawCard(); // hidden card
                Card p2card2 = this->deckP2.drawCard(); // hidden card
                this->player1.dropCard();
                this->player2.dropCard();
                prize += 2;
            }
        }
        this->gameLog.push_back(battleLog); // add this battle log the the list of turns log
        // cout << battleLog << endl;
    }

    void Game::printLastTurn()
    {
        if(this->player1.cardesTaken() == 0 && this->player2.cardesTaken() == 0) // nobody won == didnt start the game
        {
            throw runtime_error("THE FIRST TURN DID NOT PLAY");
        }
        string toPrint = this->gameLog.at(this->gameLog.size()-1);
        cout << toPrint << endl;
    }

    void Game::playAll()
    {
        if (this->player1.cardesTaken() + this->player2.cardesTaken() == 52) // when try to play all turns after the game was closed
        {
            throw runtime_error("CANNOT PLAY A TURN, RUN OUT OF CARDS");
        }
        while(this->player1.cardesTaken() + this->player2.cardesTaken() != 52)
        {
            playTurn();
        }
    }

    void Game::printWiner()
    {
        if(!this->finish)
        {
            cout << "GAME IS STILL IN PROGRESS" << endl;
            return;
        }
        cout << this->winner << endl;
    }

    void Game::printLog()
    {
        if((!finish) && this->player1.cardesTaken() == 0 && this->player2.cardesTaken() == 0)
        {
            throw runtime_error("THE FIRST TURN DID NOT PLAY");
        }
        for (int i = 0; i < this->gameLog.size(); i++)
        cout << this->gameLog[static_cast<unsigned long>(i)] << endl;
    }

    void Game::printStats()
    {
        string pl1 = this->player1.getName() + " Stats: Total Wins: "+to_string(this->player1.getWins())+
        ", Total Loses: "+to_string(this->player1.getLoses())+", Total Ties: "+to_string(this->player1.getTies())+
        this->player1.rates()+
        "Turns Played: " + to_string(this->player1.getTurnsPlayed())+", Cards Drawed: "+to_string(this->player1.getDrawsMade())+
        ", Cards Won: " + to_string(this->player1.getCardsWon()) + "."; 
        string pl2 = this->player2.getName() + " Stats: Total Wins: "+to_string(this->player2.getWins())+
        ", Total Loses: "+to_string(this->player2.getLoses())+", Total Ties: "+to_string(this->player2.getTies())+
        this->player2.rates()+
        "Turns Played: " + to_string(this->player2.getTurnsPlayed())+", Cards Drawed: "+to_string(this->player2.getDrawsMade())+
        ", Cards Won: " + to_string(this->player2.getCardsWon()) + "."; 
        cout << pl1 << endl;
        cout << pl2 << endl;
    }
}
