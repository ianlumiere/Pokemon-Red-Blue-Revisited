/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: StartingSpace.hpp
 * * This file contains the header file for the StartingSpace
 class, which is a derived class from Space. It contains only
 a default constructor and the interact() function, which is 
 a virtual function from Space.
 ***************************************************************/

#ifndef STARTINGSPACE_HPP
#define STARTINGSPACE_HPP

#include <stdio.h>
#include "Space.hpp"

class StartingSpace : public Space
{
protected:
    
public:
    StartingSpace();
    void interact();
};

#endif
