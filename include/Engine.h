#ifndef ENGINE_H
#define ENGINE_H

#include "../Factory/Fighter.h"
#include "../Factory/Mage.h"
#include "../Factory/Trainee.h"
#include "../Factory/Villain.h"
#include "../Factory/Utility.h"
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
    unsigned int in_game_day = 0;

public:
    Engine() = default;
    Engine(std::string name);

    std::unique_ptr<CharacterFactory::Trainee> player;
    //std::unique_ptr<CharacterFactory::Trainee> create_player(std::ifstream& file);
    //std::unique_ptr<CharacterFactory::Trainee> create_player(unsigned int type_id);

    void save(void);
    void load(void);
    void rest(void);
    void fight(void);
    void show(void);
    void level_up(void);
};

#endif
