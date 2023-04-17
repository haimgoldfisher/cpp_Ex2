/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

int main() {
  // Create two players with their names 
   Player p1("Alice");
   Player p2("Bob");

   Game game(p1,p2); 
   for (int i=0;i<5;i++) {
    game.playTurn();
   }
   game.printLastTurn(); // print the last turn stats. For example:
                                                    // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
                                                    // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
   cout << p1.stacksize() << endl; //prints the amount of cards left. should be 21 but can be less if a draw was played
   cout << p2.cardesTaken() << endl; // prints the amount of cards this player has won. 
   game.playAll(); //playes the game untill the end
   game.printWiner(); // prints the name of the winning player
   game.printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
   game.printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )

   cout << "*********************************************************" << endl << "MY DEMO:" << endl;
   
   cout << "Does Alice in game now? " << p1.isInGame() << " Does Bob in game now? " << p2.isInGame() << endl;
   cout << "Alice Stack: " << p1.stacksize() << " Alice Cards Taken: " << p1.cardesTaken() << endl;

   cout << "LET ALICE & BOB PLAY ONE MORE GAME:" << endl << endl;

   Game game2(p2, p1); // same players in a new LEGAL game SHOULD NOT CHANGE, ONLY AT THE FIRST LEGAL PLAYTURN()

   cout << "LETS PLAY THE FIRST MOVE OF THE NEW GAME:" << endl << endl;
   game2.playTurn();

   cout << "Does Alice in game now? " << p1.isInGame() << " Does Bob in game now? " << p2.isInGame() << endl;
   cout << "Alice Stack: " << p1.stacksize() << " Alice Cards Taken: " << p1.cardesTaken() << endl;
   game2.printStats();
   game2.playAll();

   cout << endl << "PLAY THE REST" << endl;
   cout << "Winner: ";
   game2.printWiner();
   game2.printStats();
}