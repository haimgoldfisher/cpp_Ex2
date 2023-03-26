#pragma

#include "doctest.h"
#include <stdexcept>

#include "sources/card.hpp"
#include "sources/player.hpp"
#include "sources/game.hpp"
using namespace ariel;

TEST_CASE("Player Constructor TEST:")
{
    CHECK_NOTHROW(Player()); // default constructor
    CHECK_NOTHROW(Player("David"));
    Player p1("hey");
    // string name1 = p1.getName();
    // CHECK(name1 == "hey");
    CHECK(p1.cardesTaken() == 0);
    CHECK(p1.stacksize() == 0);
}

TEST_CASE("Card Constructor TEST:") 
{ 
    // CHECK_THROWS(Card()); // cannot create a default card
    // CHECK_THROWS(Card(ACE-1, SPADE)); // illegal card value (1-13)
    // CHECK_THROWS(Card(KING+1, SPADE)); // illegal card value (1-13)
    // Card queenHearth(QUEEN, HERATH); // Q♥ Constructor
    // Card aceDiamond(ACE, DIAMOND); // A♦ Constructor
    // CHECK(queenHearth > aceDiamond); // objects operator according to VALUE
    // CHECK(queenHearth.getValue() > aceDiamond.getValue()); // the value of queen is bigger than the value of ace
    // Card aceClub(ACE, CLUB); // A♣ Constructor
    // CHECK(aceDiamond.getValue() == aceClub.getValue()); // A == A (VALUES)
    // CHECK(aceDiamond.getSuit() != aceClub.getSuit()); // ♦ != ♣ (SUITS)
}

// maybe I can build a class for DECK (and then apply: isEmpty(), Shuffle(), insertToDeck(Card c) and more...)

TEST_CASE("Game Constructor TEST:") 
{ 
    Player p1("Cat");
    CHECK_THROWS(Game(p1, p1)); // a player cannot play against himself
    Player p2("Lion");
    CHECK_NOTHROW(Game(p1,p2)); // two players case
    Player p3("Tiger");
    CHECK_THROWS(Game(p1, p3)); // a player cannot start a new game while he is in an unfinished game
}

TEST_CASE("Game Basic Methods TEST:")
{
    Player p1("Alice");
    Player p2("Bob");
    Game battle(p1, p2);
    // AT THIS PART, NO MOVE WAS PLAYED
    CHECK(p1.stacksize() == 26); // since each player gets 26 cards
    CHECK(p1.stacksize() + p2.stacksize() == 52); // since each player gets the same amount of cards
    CHECK(p1.cardesTaken() == 0); // since each player did not played
    CHECK(p1.cardesTaken() == p2.cardesTaken()); // since each player did not played
    // LETS PLAY NOW THE FIRST BATTLE
    CHECK_NOTHROW(battle.playTurn());
    CHECK_NOTHROW(battle.printLastTurn());
    CHECK_NOTHROW(battle.printStats());
    CHECK_NOTHROW(battle.printLog());
    // LOGIC CHECK
    CHECK_FALSE((p1.cardesTaken() == 0) + (p2.cardesTaken() == 0) != 1); // someone must win (at single battle / tie)
    CHECK(((p1.cardesTaken() == 0) + (p2.cardesTaken() == 0)) == 1); // double check ^
    CHECK(p1.stacksize() == p2.stacksize()); // the left cards must be equal to both players after first battle
    // MAYBE I SHOULD CHECK IF THE DECK IS MISSING THE PLAYED CARDS
    CHECK_NOTHROW(battle.playAll());
    CHECK((p1.stacksize() == 0) + (p2.stacksize() == 0) >= 1); // someone must be out of cards at that point (also both)
    CHECK_NOTHROW(battle.printWiner());
}