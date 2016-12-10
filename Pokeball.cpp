/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: Pokeball.cpp
 * * This file contains the implementation of the interact()
 function that is a virtual function from Space.
 ***************************************************************/

#include "Pokeball.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Pokeball::Pokeball()
{
    
}

void Pokeball::interact()
{
    cout << "You found 3 pokeballs! " << endl;
}