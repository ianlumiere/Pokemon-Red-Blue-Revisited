/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: Ash.cpp
 * * This file contains the implementation of the
 public functions for the Ash class. The public functions include 
 a constructor, getters and setters for Ash's current location,
 movement for Ash around the board, and checking or adjusting
 the status of the bool member variables that are protected.
 ***************************************************************/

#include "Ash.hpp"
#include "Space.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Ash::Ash()
{
    pokeballs = 0;
    caughtPokemon = false;
    gameOver = false;
    firstOak = true;
    firstPokeball = true;
    firstCharmander = true;
    firstBulbasaur = true;
    firstSquirtle = true;
}

void Ash::setCurrentLocation(Space *cL)
{
    currentLocation = cL;
}

Space* Ash::getCurrentLocation()
{
    return currentLocation;
}

void Ash::checkBackpack()
{
    cout << "Ash is checking his backpack... " << endl;
    cout << "There are currently " << pokeballs << " pokeballs in Ash's backpack! " << endl;
}

void Ash::addPokeballs(int pokeballsIn)
{
    cout << "The maximum number of Pokeballs you can carry is 5. " << endl;
    
    pokeballs += pokeballsIn;
    
    // Adjust if Ash has too many pokeballs
    if (pokeballs > 5)
    {
        pokeballs = 5;
    }
    
    cout << "Ash now has " << pokeballs << " pokeballs in his backpack. " << endl;
}

void Ash::pokeballThrow()
{
    pokeballs -= 1;
}

int Ash::pokeballInventory()
{
    return pokeballs;
}

void Ash::moveUp()
{
    if (currentLocation->getUp() != NULL)
    {
        currentLocation = currentLocation->getUp();
        cout << "You can now interact with " << currentLocation->getLocationName();
        cout << "!" << endl;
    }
    
    else
    {
        cout << "Moving up from here is not possible! " << endl;
    }
}

void Ash::moveRight()
{
    if (currentLocation->getRight() != NULL)
    {
        currentLocation = currentLocation->getRight();
        cout << "You can now interact with " << currentLocation->getLocationName();
        cout << "!" << endl;
    }
    
    else
    {
        cout << "Moving right from here is not possible! " << endl;
    }
}

void Ash::moveDown()
{
    if (currentLocation->getDown() != NULL)
    {
        currentLocation = currentLocation->getDown();
        cout << "You can now interact with " << currentLocation->getLocationName();
        cout << "!" << endl;
    }
    
    else
    {
        cout << "Moving down from here is not possible! " << endl;
    }
}

void Ash::moveLeft()
{
    if (currentLocation->getLeft() != NULL)
    {
        currentLocation = currentLocation->getLeft();
        cout << "You can now interact with " << currentLocation->getLocationName();
        cout << "!" << endl;
    }
    
    else
    {
        cout << "Moving left from here is not possible! " << endl;
    }
}

void Ash::pokemonCaught()
{
    caughtPokemon = true;
}

bool Ash::checkPokemonCaught()
{
    return caughtPokemon;
}

void Ash::ashLost()
{
    gameOver = true;
}

bool Ash::checkAshLost()
{
    return gameOver;
}

void Ash::oakInteract()
{
    firstOak = false;
}

bool Ash::checkOak()
{
    return firstOak;
}

void Ash::pokeballInteract()
{
    firstPokeball = false;
}

bool Ash::checkPokeball()
{
    return firstPokeball;
}

void Ash::charmanderInteract()
{
    firstCharmander = false;
}

bool Ash::checkCharmander()
{
    return firstCharmander;
}

void Ash::bulbasaurInteract()
{
    firstBulbasaur = false;
}

bool Ash::checkBulbasaur()
{
    return firstBulbasaur;
}

void Ash::squirtleInteract()
{
    firstSquirtle = false;
}

bool Ash::checkSquirtle()
{
    return firstSquirtle;
}
