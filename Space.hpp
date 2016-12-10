/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: Space.hpp
 * * This file contains the header file for the Abstract Space 
 class. The Space class has protected members that point in four
 different directions, which help with linking the spaces
 together, and it also has a pointer to an Ash object and a 
 string that holds the name of the space. The public functions
 include a default constructor, a constructor, a setSpace
 function that is used to link a space with spaces next to it,
 and getters for the space's name and each space that is 
 connected to it, even if the space is connected to NULL.
 Lastly, there is a virtual function called interact, which is
 used uniquely in all of Space's derived classes, which are
 StartingSpace, Pokeball, Charmander, Bulbasaur, Squirtle, and
 Oak.
 ***************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <stdio.h>
#include <string>

class Ash;

class Space
{
protected:
    Ash *ash;
    Space *up;
    Space *right;
    Space *down;
    Space *left;
    std::string locationName;
public:
    Space();
    Space(Space*, Space*, Space*, Space*);
    void setSpace(Ash*, Space*, Space*, Space*, Space*, std::string);
    std::string getLocationName();
    Space* getUp();
    Space* getRight();
    Space* getDown();
    Space* getLeft();
    virtual void interact() = 0;
};

#endif
