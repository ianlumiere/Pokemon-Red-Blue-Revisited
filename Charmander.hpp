/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: Charmander.hpp
 * * This file contains the header file for the Charmander
 class, which is a derived class from Space. It contains only
 a default constructor and the interact() function, which is
 a virtual function from Space.
 ***************************************************************/

#ifndef CHARMANDER_HPP
#define CHARMANDER_HPP

#include <stdio.h>
#include "Space.hpp"

class Charmander : public Space
{
protected:
    
public:
    Charmander();
    void interact();
};

#endif