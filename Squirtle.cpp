/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: Squirtle.cpp
 * * This file contains the implementation of the interact()
 function that is a virtual function from Space.
 ***************************************************************/

#include "Squirtle.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Squirtle::Squirtle()
{
    
}

void Squirtle::interact()
{
    cout << "A wild Squirtle appeared! " << endl;
}