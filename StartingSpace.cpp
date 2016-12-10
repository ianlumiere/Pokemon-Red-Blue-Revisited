/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: StartingSpace.cpp
 * * This file contains the implementation of the interact()
 function that is a virtual function from Space.
 ***************************************************************/

#include "StartingSpace.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

StartingSpace::StartingSpace()
{
    
}

void StartingSpace::interact()
{
    cout << "This is the starting space! " << endl;
    cout << "There is nothing to do here! " << endl;
}