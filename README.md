RPG Game Project
=========

v2
--

* v2 of the game features (sprint1 + sprint2)
* build/Makefile: `make` to build the application , `make clean` to clean
* Organization: cpp files in src folder, header files in include
* For playing, first type make in build folder, and run ./RPG_GAME executable in main folder.

Features
========

Main menu
---------

* New Game: start a game, initialize a player (ask for name) and present the main game loop
* Load Game: load player stats from a save file and present the main game loop
* Exit: terminate the program


Main Game loop
--------------
Using Game class to manage the game loop.  
As long as the player is alive, the following options are given:

* Fight: dummy fight function, just lose some HP
* Show stats: display the current player's statistics
* Save: save the game state to a given save file (see save/load feature)
* Exit: terminate the program


Player Stats
------------
Use character class to mangage player's status and data
store as private member in player class

* HP (health points)
* Max HP
* Name
* defense points
* attack points

The player is alive as long as HP > 0


Save/Load feature
-----------------

Data are saved in clear text (here a new line for a var)

* Saving: Use the player name as the save file name and store the player's stats in a text file. Override existing save if already existing.
* Loading: ask the player's name for a save file name and load it.
