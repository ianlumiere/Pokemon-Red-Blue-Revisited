/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: Oak.cpp
 * * This file contains the implementation of the interact()
 function that is a virtual function from Space.
 ***************************************************************/

#include "Oak.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Oak::Oak()
{

}

void Oak::interact()
{
    cout << "Hello! My name is Professor Oak. " << endl;
    cout << "I need help conducting my research. " << endl;
    cout << "I need you to go and catch me a Pokemon! " << endl;
    cout << "Here are 5 Pokeballs to help you on this quest. " << endl;
    cout << "You'll need to use Pokeballs to catch a Pokemon. " << endl;
    cout << "If you use all pokeballs on the map and fail to catch a Pokemon " << endl;
    cout << "or if all 3 Pokemon run away, then you lose! " << endl;
}

