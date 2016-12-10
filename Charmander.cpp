/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: Charmander.cpp
 * * This file contains the implementation of the interact()
 function that is a virtual function from Space.
 ***************************************************************/

#include "Charmander.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Charmander::Charmander()
{
    
}

void Charmander::interact()
{
    cout << "A wild Charmander appeared! " << endl;
}