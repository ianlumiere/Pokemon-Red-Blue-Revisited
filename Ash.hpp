/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: Ash.hpp
 * * This file contains the header file for the Ash class.
 The protected members track Ash's current location, the current
 number of pokeballs he has in his backpack, whether Ash has
 caught a pokemon, whether Ash has lost the game because the
 pokemon all ran away, and whether Ash has already interacted
 with each of the spaces. The public functions include a
 constructor, getters and setters for Ash's current location,
 movement for Ash around the board, and checking or adjusting
 the status of the bool member variables that are protected.
 ***************************************************************/

#ifndef ASH_HPP
#define ASH_HPP

#include <stdio.h>

class Space;

class Ash
{
protected:
    int pokeballs;
    Space *currentLocation;
    bool caughtPokemon;
    bool gameOver;
    bool firstOak;
    bool firstPokeball;
    bool firstCharmander;
    bool firstSquirtle;
    bool firstBulbasaur;
public:
    Ash();
    void setCurrentLocation(Space*);
    Space* getCurrentLocation();
    void checkBackpack();
    void addPokeballs(int);
    void pokeballThrow();
    int pokeballInventory();
    void moveUp();
    void moveRight();
    void moveDown();
    void moveLeft();
    void pokemonCaught();
    bool checkPokemonCaught();
    void ashLost();
    bool checkAshLost();
    void oakInteract();
    bool checkOak();
    void pokeballInteract();
    bool checkPokeball();
    void charmanderInteract();
    bool checkCharmander();
    void bulbasaurInteract();
    bool checkBulbasaur();
    void squirtleInteract();
    bool checkSquirtle();
};

#endif