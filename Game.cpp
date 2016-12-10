/***************************************************************
 * * Author: Ian Lumiere
 * * Date: December 3, 2016
 * * Description: CS 162 final: Game.cpp
 * * This file contains the implementation of the Game
 constructor and destructor, as well as the run() function and
 getAsh() function.
 ***************************************************************/

#include "Game.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Game::Game()
{
    // Create all objects
    startingSpace = new StartingSpace;
    pokeball = new Pokeball;
    charmander = new Charmander;
    bulbasaur = new Bulbasaur;
    squirtle = new Squirtle;
    oak = new Oak;
    
    // Create Ash
    ash = new Ash;
    
    // Set Up the Board
    startingSpace->setSpace(ash, NULL, oak, NULL, NULL, "the Starting Space");
    oak->setSpace(ash, NULL, charmander, NULL, startingSpace, "Oak");
    charmander->setSpace(ash, NULL, pokeball, bulbasaur, oak, "Charmander");
    bulbasaur->setSpace(ash, charmander, squirtle, NULL, NULL, "Bulbasaur");
    pokeball->setSpace(ash, NULL, NULL, squirtle, charmander, "the Pokeball");
    squirtle->setSpace(ash, pokeball, NULL, NULL, bulbasaur, "Squirtle");
    
    // Set Ash's Starting Point
    ash->setCurrentLocation(startingSpace);
}

Game::~Game()
{
    // delete pointers and set them to NULL
    delete startingSpace;
    startingSpace = NULL;
    
    delete pokeball;
    pokeball = NULL;
    
    delete charmander;
    charmander = NULL;
    
    delete bulbasaur;
    bulbasaur = NULL;
    
    delete squirtle;
    squirtle = NULL;
    
    delete oak;
    oak = NULL;

    delete ash;
    ash = NULL;
}

// This function runs the loop of the game until the user wins or loses
void Game::run()
{
    char playerMove;
    
    // Opening greeting and instructions
    cout << "Welcome to Pallet Town, Ash! " << endl;
    cout << "To win, you must catch 1 Pokemon! " << endl;
    cout << "Below is a map of the world and a key: " << endl;
    cout << "   T   O   C   P " << endl;
    cout << "           B   S " << endl;
    cout << "Key: " << endl;
    cout << "   T: Starting Space " << endl;
    cout << "   O: Oak " << endl;
    cout << "   C: Charmander " << endl;
    cout << "   P: Pokeball (hint: go here to find extra pokeballs) " << endl;
    cout << "   B: Bulbasaur " << endl;
    cout << "   S: Squirtle " << endl;

    cout << "Walk over to Professor Oak (press d) and interact (press i) to begin! " << endl;
    
    do {
        // This is the menu of inputs that a user can use to go through the game
        cout << "To walk, enter: " << endl;
        cout << "   w for up. " << endl;
        cout << "   d for right. " << endl;
        cout << "   s for down. " << endl;
        cout << "   a for left. " << endl;
        cout << "To interact with the current space: " << endl;
        cout << "   press i. " << endl;
        cout << "To check your backpack: " << endl;
        cout << "   press b. " << endl;
        cout << "To exit: " << endl;
        cout << "   press x. " << endl;
        
        cin >> playerMove;
        
        while ((playerMove != 'w') && (playerMove != 'W') && (playerMove != 'd') && (playerMove != 'D') && (playerMove != 's') && (playerMove != 'S') && (playerMove != 'a') && (playerMove != 'A') && (playerMove!= 'i') && (playerMove != 'I') && (playerMove != 'b') && (playerMove != 'B') && (playerMove != 'x') && (playerMove != 'X'))
        {
            cin.clear();
            cout << "You entered an invalid input! " << endl;
            cout << "To walk, enter: " << endl;
            cout << "   w for up. " << endl;
            cout << "   d for right. " << endl;
            cout << "   s for down. " << endl;
            cout << "   a for left. " << endl;
            cout << "To interact with the current space: " << endl;
            cout << "   press i. " << endl;
            cout << "To check your backpack: " << endl;
            cout << "   press b. " << endl;
            cout << "To exit: " << endl;
            cout << "   press x. " << endl;
            
            cin >> playerMove;
        }
        
        // Move up
        if ((playerMove == 'w') || (playerMove == 'W'))
        {
            ash->moveUp();
        }
        
        // Move right
        else if ((playerMove == 'd') || (playerMove == 'D'))
        {
            ash->moveRight();
        }
        
        // Move down
        else if ((playerMove == 's') || (playerMove == 'S'))
        {
            ash->moveDown();
        }
        
        // Move left
        else if ((playerMove == 'a') || (playerMove == 'A'))
        {
            ash->moveLeft();
        }
        
        // Interact
        else if ((playerMove == 'i') || (playerMove == 'I'))
        {
            // StartingSpace
            if (ash->getCurrentLocation()->getLocationName() == "the Starting Space")
            {
                ash->getCurrentLocation()->interact();
            }
            
            // Oak
            if (ash->getCurrentLocation()->getLocationName() == "Oak")
            {
                // Check if the user has already intereacted with Oak
                if(ash->checkOak() == true)
                {
                    // Interact, add the pokeballs, and adjust the first interaction variable in the Ash class
                    ash->getCurrentLocation()->interact();
                    ash->addPokeballs(5);
                    ash->oakInteract();
                }
                
                else
                {
                    cout << "You have already interacted with Professor Oak! " << endl;
                }
            }
            
            // Charmander
            if (ash->getCurrentLocation()->getLocationName() == "Charmander")
            {
                // Check if the user has already interacted with Charmander
                if(ash->checkCharmander() == true)
                {
                    // Interact, and try to catch the pokemon before they run away
                    ash->getCurrentLocation()->interact();
                    
                    // Attempt to catch the pokemon
                    char pokeballThrow;
                    int pokemonCatch;
                    int ran = 0;
                    
                    // Check if Ash has enough Pokeballs to catch the Pokemon
                    if (ash->pokeballInventory() < 1)
                    {
                        cout << "Ash has 0 pokeballs and cannot catch the pokemon! " << endl;
                        cout << "The Charmander ran away! " << endl;
                        
                        // Update the interaction history
                        ash->charmanderInteract();
                    }
                    
                    else
                    {
                        do
                        {
                            cout << "To catch a pokemon, press P to throw a pokeball! " << endl;
                            
                            cin >> pokeballThrow;
                            
                            while ((pokeballThrow != 'p') && (pokeballThrow != 'P'))
                            {
                                cout << "You entered an invalid input! " << endl;
                                cout << "To catch a pokemon, press P to throw a pokeball! " << endl;
                                
                                cin >> pokeballThrow;
                            }
                            
                            cout << "You threw a pokeball! " << endl;
                            
                            // Subtract a Pokeball
                            if ((pokeballThrow == 'p') || (pokeballThrow == 'P'))
                            {
                                ash->pokeballThrow();
                            }
                            
                            // Generate random chance of catching (25% chance)
                            pokemonCatch = (rand() % 4) + 1;
                            
                            if (pokemonCatch == 1)
                            {
                                cout << "You caught the Charmander! " << endl;
                                cout << "You win the game! " << endl;
                                ash->pokemonCaught();
                            }
                            
                            else
                            {
                                cout << "Oh no! The Charmander broke free! " << endl;
                            
                                // Generate random chance of the pokemon running away (25% chance)
                                ran = (rand() % 4) + 1;
                                
                                if (ran == 1)
                                {
                                    cout << "The Charmander ran away! " << endl;
                                }
                                
                                else
                                {
                                    // Check if Ash has enough Pokeballs to catch the Pokemon
                                    if (ash->pokeballInventory() < 1)
                                    {
                                        cout << "Ash has 0 pokeballs and cannot catch the pokemon! " << endl;
                                        cout << "The Charmander ran away! " << endl;
                                        
                                        // Update the interaction history
                                        ash->charmanderInteract();
                                    }
                                }
                            }
                            
                        } while ((ran != 1) && (ash->pokeballInventory() > 0) && (ash->checkPokemonCaught() == false));
                        
                        // Update the interaction history
                        ash->charmanderInteract();
                    }
                    
                }
                
                else
                {
                    cout << "The Charmander already ran away! " << endl;
                }
            }
            
            // Bulbasaur
            if (ash->getCurrentLocation()->getLocationName() == "Bulbasaur")
            {
                // Check if the user has already interacted with Bulbasaur
                if(ash->checkBulbasaur() == true)
                {
                    // Interact, and try to catch the pokemon before they run away
                    ash->getCurrentLocation()->interact();
                    
                    // Attempt to catch the pokemon
                    char pokeballThrow;
                    int pokemonCatch;
                    int ran = 0;
                    
                    // Check if Ash has enough Pokeballs to catch the Pokemon
                    if (ash->pokeballInventory() < 1)
                    {
                        cout << "Ash has 0 pokeballs and cannot catch the pokemon! " << endl;
                        cout << "The Bulbasaur ran away! " << endl;
                        
                        // Update the interaction history
                        ash->bulbasaurInteract();
                    }
                    
                    else
                    {
                        do
                        {
                            cout << "To catch a pokemon, press P to throw a pokeball! " << endl;
                            
                            cin >> pokeballThrow;
                            
                            while ((pokeballThrow != 'p') && (pokeballThrow != 'P'))
                            {
                                cout << "You entered an invalid input! " << endl;
                                cout << "To catch a pokemon, press P to throw a pokeball! " << endl;
                                
                                cin >> pokeballThrow;
                            }
                            
                            cout << "You threw a pokeball! " << endl;
                            
                            // Subtract a Pokeball
                            if ((pokeballThrow == 'p') || (pokeballThrow == 'P'))
                            {
                                ash->pokeballThrow();
                            }
                            
                            // Generate random chance of catching (25% chance)
                            pokemonCatch = (rand() % 4) + 1;
                            
                            if (pokemonCatch == 1)
                            {
                                cout << "You caught the Bulbasaur! " << endl;
                                cout << "You win the game! " << endl;
                                ash->pokemonCaught();
                            }
                            
                            else
                            {
                                cout << "Oh no! The Bulbasaur broke free! " << endl;
                                
                                // Generate random chance of the pokemon running away (25% chance)
                                ran = (rand() % 4) + 1;
                                
                                if (ran == 1)
                                {
                                    cout << "The Bulbasaur ran away! " << endl;
                                }
                                
                                else
                                {
                                    // Check if Ash has enough Pokeballs to catch the Pokemon
                                    if (ash->pokeballInventory() < 1)
                                    {
                                        cout << "Ash has 0 pokeballs and cannot catch the pokemon! " << endl;
                                        cout << "The Bulbasaur ran away! " << endl;
                                        
                                        // Update the interaction history
                                        ash->bulbasaurInteract();
                                    }
                                }
                            }
                            
                        } while ((ran != 1) && (ash->pokeballInventory() > 0) && (ash->checkPokemonCaught() == false));
                        
                        // Update the interaction history
                        ash->bulbasaurInteract();
                    }
                    
                }
                
                else
                {
                    cout << "The Bulbasaur already ran away! " << endl;
                }
            }
            
            // Squirtle
            if (ash->getCurrentLocation()->getLocationName() == "Squirtle")
            {
                // Check if the user has already interacted with Squirtle
                if(ash->checkSquirtle() == true)
                {
                    // Interact, and try to catch the pokemon before they run away
                    ash->getCurrentLocation()->interact();
                    
                    // Attempt to catch the pokemon
                    char pokeballThrow;
                    int pokemonCatch;
                    int ran = 0;
                    
                    // Check if Ash has enough Pokeballs to catch the Pokemon
                    if (ash->pokeballInventory() < 1)
                    {
                        cout << "Ash has 0 pokeballs and cannot catch the pokemon! " << endl;
                        cout << "The Squirtle ran away! " << endl;
                        
                        // Update the interaction history
                        ash->squirtleInteract();
                    }
                    
                    else
                    {
                        do
                        {
                            cout << "To catch a pokemon, press P to throw a pokeball! " << endl;
                            
                            cin >> pokeballThrow;
                            
                            while ((pokeballThrow != 'p') && (pokeballThrow != 'P'))
                            {
                                cout << "You entered an invalid input! " << endl;
                                cout << "To catch a pokemon, press P to throw a pokeball! " << endl;
                                
                                cin >> pokeballThrow;
                            }
                            
                            cout << "You threw a pokeball! " << endl;
                            
                            // Subtract a Pokeball
                            if ((pokeballThrow == 'p') || (pokeballThrow == 'P'))
                            {
                                ash->pokeballThrow();
                            }
                            
                            // Generate random chance of catching (25% chance)
                            pokemonCatch = (rand() % 4) + 1;
                            
                            if (pokemonCatch == 1)
                            {
                                cout << "You caught the Squirtle! " << endl;
                                cout << "You win the game! " << endl;
                                ash->pokemonCaught();
                            }
                            
                            else
                            {
                                cout << "Oh no! The Squirtle broke free! " << endl;
                                
                                // Generate random chance of the pokemon running away (25% chance)
                                ran = (rand() % 4) + 1;
                                
                                if (ran == 1)
                                {
                                    cout << "The Squirtle ran away! " << endl;
                                }
                                
                                else
                                {
                                    // Check if Ash has enough Pokeballs to catch the Pokemon
                                    if (ash->pokeballInventory() < 1)
                                    {
                                        cout << "Ash has 0 pokeballs and cannot catch the pokemon! " << endl;
                                        cout << "The Squirtle ran away! " << endl;
                                        
                                        // Update the interaction history
                                        ash->squirtleInteract();
                                    }
                                }
                            }
                            
                        } while ((ran != 1) && (ash->pokeballInventory() > 0) && (ash->checkPokemonCaught() == false));
                        
                        // Update the interaction history
                        ash->squirtleInteract();
                    }
                    
                }
                
                else
                {
                    cout << "The Squirtle already ran away! " << endl;
                }
            }
            
            // Pokeball
            if (ash->getCurrentLocation()->getLocationName() == "the Pokeball")
            {
                // Check if the user has already interacted with the Pokeball
                if(ash->checkPokeball() == true)
                {
                    // Interact, add the pokeballs, and adjust the first interaction variable in the Ash class
                    ash->getCurrentLocation()->interact();
                    ash->addPokeballs(3);
                    ash->pokeballInteract();
                }
                
                else
                {
                    cout << "You have already interacted with the Pokeball! " << endl;
                }
            }
        }
        
        // Check backpack
        else if ((playerMove == 'b') || (playerMove == 'B'))
        {
            ash->checkBackpack();
        }
        
        else if ((playerMove == 'x') || (playerMove == 'X'))
        {
            cout << "You are now exiting the game. " << endl;
            ash->ashLost();
        }
        
        // Test if the lose condition of all of the pokemon running away was triggered
        if ((ash->checkBulbasaur() == false) && (ash->checkCharmander() == false) && (ash->checkSquirtle() == false) && (ash->checkPokemonCaught() == false))
        {
            cout << "All of the Pokemon ran away! " << endl;
            cout << "Ash lost the game! " << endl;
            ash->ashLost();
        }
        
        // Test if Ash completely ran out of Pokeballs and has no potential of catching a Pokemon
        else if ((ash->checkOak() == false) && (ash->checkPokeball() == false))
        {
            if (ash->pokeballInventory() < 1)
            {
                cout << "Ash has 0 pokeballs and cannot catch any pokemon! " << endl;
                cout << "There are no other pokeballs on the map! " << endl;
                cout << "Ash lost the game! " << endl;
                ash->ashLost();
            }
        }
        
    // Continue to run the loop while neither a win condition nor a lose condition has triggered
    } while ((ash->checkPokemonCaught() == false) && (ash->checkAshLost() == false));
}

Ash* Game::getAsh()
{
    return ash;
}
