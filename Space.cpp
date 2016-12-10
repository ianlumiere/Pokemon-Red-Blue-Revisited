/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: Space.cpp
 * * This file contains the implementation of the public
 functions from the Abstract Space class. The default constructor
 sets each directional linking pointer to NULL. The constructor
 sets it to the 4 corresponding pointers that are passed
 as parameters. The setSpace function sets each directional
 linking pointer to the 4 corresponding pointers that are
 passed as parameters, as well as taking a pointer to an Ash
 object and a string that ties to the Space's name. The getters
 simply return the locationName, or the space that is above,
 to the right of, below, or to the left of the space, and returns
 NULL if there is no space in one of those directions.
 ***************************************************************/

#include "Space.hpp"
#include "Ash.hpp"

Space::Space()
{
    up = NULL;
    right = NULL;
    down = NULL;
    left = NULL;
}

Space::Space(Space *u, Space *r, Space *d, Space *l)
{
    up = u;
    right = r;
    down = d;
    left = l;
}

void Space::setSpace(Ash *a, Space *u, Space *r, Space *d, Space *l, std::string lN)
{
    ash = a;
    up = u;
    right = r;
    down = d;
    left = l;
    locationName = lN;
}

std::string Space::getLocationName()
{
    return locationName;
}

Space* Space::getUp()
{
    // Check if there is a Space that is above the current one
    if (up != NULL)
    {
        return up;
    }
    
    else
    {
        return NULL;
    }
}

Space* Space::getRight()
{
    // Check if there is a Space that is right of the current one
    if (right != NULL)
    {
        return right;
    }
    
    else
    {
        return NULL;
    }
}

Space* Space::getDown()
{
    // Check if there is a Space that is below the current one
    if (down != NULL)
    {
        return down;
    }
    
    else
    {
        return NULL;
    }
}

Space* Space::getLeft()
{
    // Check if there is a Space that is left of the current one
    if (left != NULL)
    {
        return left;
    }
    
    else
    {
        return NULL;
    }
}