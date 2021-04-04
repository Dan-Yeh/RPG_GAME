#ifndef ENGINE_H
#define ENGINE_H

#include "../Factory/Fighter.h"
#include "../Factory/Mage.h"
#include "../Factory/Trainee.h"
#include "../Factory/Villain.h"
#include "../Factory/CharacterFactory.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#define DIR_PATH "./saves/"

/**
 * Class for managing game engine utilities
 * 
 * */

class Engine {
private:
    std::string file_name;

public:
    Engine() = default;
    Engine(std::string name);

    std::unique_ptr<Trainee> player;
    unsigned int in_game_day = 0;

    void save(void);
    void load(void);
    void rest(void);
    void fight(void);
    void show(void);
    void level_up(void);
};

#endif
