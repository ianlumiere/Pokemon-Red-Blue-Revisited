/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: Bulbasaur.cpp
 * * This file contains the implementation of the interact()
 function that is a virtual function from Space.
 ***************************************************************/

#include "Bulbasaur.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Bulbasaur::Bulbasaur()
{
    
}

void Bulbasaur::interact()
{
    cout << "A wild Bulbasaur appeared! " << endl;
}