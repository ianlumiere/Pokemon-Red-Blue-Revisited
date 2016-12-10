/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: Squirtle.hpp
 * * This file contains the header file for the Squirtle
 class, which is a derived class from Space. It contains only
 a default constructor and the interact() function, which is
 a virtual function from Space.
 ***************************************************************/

#ifndef SQUIRTLE_HPP
#define SQUIRTLE_HPP

#include <stdio.h>
#include "Space.hpp"

class Squirtle : public Space
{
protected:
    
public:
    Squirtle();
    void interact();
};

#endif
