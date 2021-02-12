Changelog
=========

v3
--

* BaseClass: added level to the stats
* Added a levelUp mechanic, level up after each fight and increase stats a bit depending on the current level and class
* Added new playable RPG classes: player starts as Trainee, can become Mage or Warrior after a certain level cap, see class description below
* Moved all playable classes definitions and the CharacterFactory to a new project subfolder
* Modified the CharacterFactory and save/load function to accommodate for new classes
* Added a new RNG namespace with a rollDice function to generate random roll dices (see Warrior's critical strikes)
* When fighting, ask the attacker for its damage instead of just using his attack stat (see Warrior and Mage).


Features
========

Main menu
---------

* New Game: start a game, initialize a player (ask for name) and present the main game loop
* Load Game: load player stats from a save file and present the main game loop
* Exit: terminate the program


Main Game loop
--------------

As long as the player is alive, the following options are given:

* Fight: fight against an enemy (dummy goblin all the time), takes a day
* Rest: fully heal the player, takes a day
* Show stats: display the current player's stats
* Upgrade Class: if he can, the player can upgrade his current class
* Save: save the game state to a given save file (see save/load feature)
* Exit: terminate the program


Character Stats
---------------

A character can be the player or an enemy.

Stored in a BaseClass Object.

* Name: name of the character
* Type: name of the current class
* HP: current HP
* Max HP: maximum HP, resting set HP to this value
* Attack: attack stat for fighting
* Defense: defense stat for fighting

A character is alive as long as HP > 0.

The player character is an object of a child class of BaseClass.

### Trainee 

Starting class for a new player, upgrade to Warrior or Mage.

Stats similar to BaseClass.

Gain a bit of stats points at level up.

### Warrior

Upgrade from Trainee, cannot be upgraded.

The warrior has a crit stat representing his critical chance percentage. Each time he attacks, he rolls a dice and if it is a critical strike he inflicts 1.5 times his attack as damage.

Better stat increase at level up than the Trainee.

### Mage

Upgrade from Trainee, cannot be upgraded.

The Mage has 3 new stats: 

* Mana: magical resource used to cast spell when attacking
* Max Mana: maximum Mana, resting set Mana to this value
* Magic: equivalent to the attack stat for fighting when using a spell

The Mage start with more Magic than his Attack and his Magic stat increase faster than his attack one when leveling up.

When resting he restores his HP and Mana.

When attacking if he has enough mana to cast a spell, he uses it and deals damage using his magic stat, otherwise he attacks normally with his attack stat.

Fights
------

Two characters fight as long as both are alive.

Each deals damages, based on their Class that is then reduced by the defender's defense stat, to the other at the same time.
Repeat until one dies.

If the player wins the fight, he gains a level.

Save/Load feature
-----------------

Data are saved in clear text (here csv format).
It uses the CharacterFactory to serialize/deserialize a player character.

* Saving: ask the player for the save file name and store the game state in it. Override existing save if already existing.
* Loading: ask the player for a save file name and load it.


Old Changelog
=============

v1
--

* v1 of the game features
* Makefile: `make` to build the application (by default `miniRPG`), `make clean` to clean


v2
--

* moved the source to src/ and saves to saves/
* Encapsulated the Engine in a class
* Introduced a Rest mechanic in the main game loop to restore HP
* Introduced a day counter (int) in the Engine to count how many in game day passed (fight and rest increase the day counter)
* Introduced BaseClass for the game characters, refactored the player to use be an instance of this class (using unique_ptr)
* Introduced CharacterFactory namespace and functions to create characters and serialize/deserialize them
* Modified the save/load function to save/load the engine state (dayCounter and player, using the CharacterFactory)
