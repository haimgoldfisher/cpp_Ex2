#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{
    class Player
    {
        string name;
        int stackSize = 0;
        int cardsTaken = 0;

        public:
        Player(string newName);
        int stacksize();
        int cardesTaken();
    };
}