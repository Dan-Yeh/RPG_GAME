RPG Game Project
=====
A command-line based RPG game written in C++

Usage
=====
Play
--------------------------
First compile the executable
```
rpg-adventure-game/build: make clean
rpg-adventure-game/build: make
```
Then run the execuatble
```
rpg-adventure-game: ./RPG_GAME

```

Profiling
--------------------------
First compile with flag -pg mode and use TEST settings in program
```
rpg-adventure-game/build: make clean
rpg-adventure-game/build: make gprof
```

Generate profile report
```
rpg-adventure-game: ./RPG_GAME
rpg-adventure-game: gprof ./RPG_GAME gmon.out > report.txt
```

Features
========

Main menu
---------

* New Game: start a game, initialize a player (ask for name) and present the main game loop
* Load Game: load player stats from a save file and present the main game loop
* Demo: A simple demo of basics player behaviors such as show, fight, save, etc
* Exit: terminate the program


Main Game loop
--------------

As long as the player is alive, the following options are given:

* Fight: fight against an enemy (dummy goblin all the time), takes a day
* Rest: fully heal the player, takes a day
* Show stats: display the current player's stats
* Save: save the game state to a given save file (see save/load feature)
* Exit: terminate the program


Character Stats
---------------

A character can be the player or an enemy.

Stored in a BaseClass Object.

* Name: name of the character
* Type Name: name of the current class
* Type ID: id of a current class
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

if current level equal to transfer level, player could choose a profession (Fighter, Mage) or not

### Fighter

Upgrade from Trainee, cannot be upgraded.

The fighter has a crit stat representing his critical chance percentage. Each time he attacks, he rolls a dice and if it is a critical strike he inflicts 1.5 times his attack as damage.

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

Data are saved in clear text.
It uses the CharacterFactory to serialize/deserialize a player character.

* Saving: ask the player for the save file name and store the game state in it. Override existing save if already existing.
* Loading: ask the player for a save file name and load it.
