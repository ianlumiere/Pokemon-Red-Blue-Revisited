/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: Game.hpp
 * * This file contains the header file for the Game class.
 The class has pointers to each object as protected members.
 The public functions are a constructor, destructor, a run()
 function, which effectively runs the loop of the game until
 the user wins or loses, and a getAsh function that returns
 a pointer to an Ash object.
 ***************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <stdio.h>
#include "Ash.hpp"
#include "Space.hpp"
#include "StartingSpace.hpp"
#include "Pokeball.hpp"
#include "Charmander.hpp"
#include "Bulbasaur.hpp"
#include "Squirtle.hpp"
#include "Oak.hpp"

class Game
{
protected:
    Ash *ash;
    StartingSpace *startingSpace;
    Pokeball *pokeball;
    Charmander *charmander;
    Bulbasaur *bulbasaur;
    Squirtle *squirtle;
    Oak *oak;
public:
    Game();
    ~Game();
    void run();
    Ash* getAsh();
};

#endif
