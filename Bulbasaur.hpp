/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: Bulbasaur.hpp
 * * This file contains the header file for the Bulbasaur
 class, which is a derived class from Space. It contains only
 a default constructor and the interact() function, which is
 a virtual function from Space.
 ***************************************************************/

#ifndef BULBASAUR_HPP
#define BULBASAUR_HPP

#include <stdio.h>
#include "Space.hpp"

class Bulbasaur : public Space
{
protected:
    
public:
    Bulbasaur();
    void interact();
};

#endif
