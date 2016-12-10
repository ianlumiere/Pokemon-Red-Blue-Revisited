/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: main.cpp
 * * This file contains the main function of the program. main
 seeds a random number generator and creates a pointer to
 a new Game object. main then calls the run() function of
 the game object, which runs the game. main then deletes the
 g1 object and sets it to NULL.
 ***************************************************************/


#include <iostream>
#include <cstdlib>
#include <limits>
#include <ctime>

#include "Game.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{    
    // Seed the random number generator for Pokemon catching
    unsigned int seed;
    seed = time(0);
    srand(seed);
    
    Game g1;
    
    g1.run();
        
    return 0;
}
