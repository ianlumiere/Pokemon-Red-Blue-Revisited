/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: Oak.hpp
 * * This file contains the header file for the Oak
 class, which is a derived class from Space. It contains only
 a default constructor and the interact() function, which is
 a virtual function from Space.
 ***************************************************************/

#ifndef OAK_HPP
#define OAK_HPP

#include <stdio.h>
#include "Space.hpp"

class Oak : public Space
{
protected:

public:
    Oak();
    void interact();
};

#endif