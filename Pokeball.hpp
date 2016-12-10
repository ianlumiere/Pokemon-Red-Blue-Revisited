/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: Pokeball.hpp
 * * This file contains the header file for the Pokeball
 class, which is a derived class from Space. It contains only
 a default constructor and the interact() function, which is
 a virtual function from Space.
 ***************************************************************/

#ifndef POKEBALL_HPP
#define POKEBALL_HPP

#include <stdio.h>
#include "Space.hpp"

class Pokeball : public Space
{
protected:
    
public:
    Pokeball();
    void interact();
};

#endif
