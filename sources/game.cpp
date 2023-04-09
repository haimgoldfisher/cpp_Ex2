#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
using namespace std;

#include "game.hpp"
#include "player.hpp"

namespace ariel
{
    Game::Game(Player& pl1, Player& pl2) : player1(pl1), player2(pl2) // references to the players, so the game will modify their arrtibutes
    {
        player1.setStack(26);
        player2.setStack(26);
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
        else 
        {
            this->winner = "Draw";
        }
        this->finish = true;
        this->player1.endGame();
        this->player2.endGame();
    }

    void Game::playTurn()
    {
        if (this->player1.stacksize() == 0 || this->player2.stacksize() == 0)
        {
            throw runtime_error("CANNOT PLAY A TURN, RUN OUT OF CARDS");
        }
        if (this->player1.cardesTaken() == 0 && this->player2.cardesTaken() == 0) // its first turn
        {
            if (&this->player1 == &this->player2) // same player case
            {
                throw runtime_error("A PLAYER CANNOT PLAY AGAINST ITSELF");
            }
            if (this->player1.isInGame() || this->player2.isInGame())
            {
                throw runtime_error("ONE OR MORE PLAYERS ALREADY PLAYING");
            }
            vector<Card> deck;
            for (int i = 1; i <= 4; i++) // {EMPTY = 0, CLUBS = 1, DIAMONDS = 2, HEARTS = 3, SPADES = 4}
            {
                Suit suit = (Suit)i;
                for (int val = 2; val <= ACE; val++) // 2 to 14
                {
                    Card newCard(val, suit);
                    deck.push_back(newCard);
                }
            }
            srand(time(0));
            random_shuffle(deck.begin(), deck.end());
            while(!deck.empty())
            {
                Card toInsert1 = deck[static_cast<unsigned long>(deck.size()-1)];
                this->deckP1.push_back(toInsert1);
                deck.pop_back();
                Card toInsert2 = deck[static_cast<unsigned long>(deck.size()-1)];
                this->deckP2.push_back(toInsert2);
                deck.pop_back();
            }
            this->player1.startGame();
            this->player2.startGame();
        }
        battle(0, "", "");
    }

    void Game::battle(int prize, string battleWinner, string battleLog)
    {
        while(true)
        {
            if (this->player1.stacksize() == 0 || this->player1.stacksize() == 0)
            {
                battleLog += "Run out of cards.";
                if(prize != 0)
                {
                    player1.setTaken(prize/2);
                    player2.setTaken(prize/2);
                }
                break;
            }
            Card p1card = this->deckP1[static_cast<unsigned long>(this->deckP1.size()-1)];
            this->deckP1.pop_back();
            Card p2card = this->deckP2[static_cast<unsigned long>(this->deckP2.size()-1)];
            this->deckP2.pop_back();
            this->player1.dropCard();
            this->player2.dropCard();
            prize += 2;
            string p1 = p1card.getValAsStr() + " of " + p1card.getSuitAsStr();
            string p2 = p2card.getValAsStr() + " of " + p2card.getSuitAsStr();
            battleLog += this->player1.getName()+" played "+p1+" "+this->player2.getName()+ " played "+p2+". ";
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
                battleLog += battleWinner+" wins."; // name of winner
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
                battleLog += battleWinner+" wins."; // name of winner
                break;
            }
            else // TIE CASE
            {
                battleLog += "Draw. ";
                this->player1.addTie();
                this->player2.addTie();
                if (this->player1.stacksize() == 0 || this->player1.stacksize() == 0) // if cant place one more hidden card
                {
                    battleLog += "Run out of cards.";
                    this->player1.setTaken(prize/2);
                    this->player2.setTaken(prize/2);
                    break;
                }
                Card p1card2 = this->deckP1[static_cast<unsigned long>(this->deckP1.size()-1)]; // place one hidden card
                this->deckP1.pop_back();
                Card p2card2 = this->deckP2[static_cast<unsigned long>(this->deckP2.size()-1)]; // place one hidden card
                this->deckP2.pop_back();
                this->player1.dropCard();
                this->player2.dropCard();
                prize += 2;
            }
        }
        this->gameLog.push_back(battleLog);
        // cout << battleLog << endl;
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
        while(this->player1.stacksize() > 0 && this->player2.stacksize() > 0)
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
        string pl1 = this->player1.getName() + " Stats: Total wins: "+to_string(this->player1.getWins())+
        ", Total Loses: "+to_string(this->player1.getLoses())+", Total Ties:"+to_string(this->player1.getTies())+".";
        string pl2 = this->player2.getName() + " Stats: Total wins: "+to_string(this->player2.getWins())+
        ", Total Loses: "+to_string(this->player2.getLoses())+", Total Ties:"+to_string(this->player2.getTies())+".";
        cout << pl1 << endl;
        cout << pl2 << endl;
    }
}
