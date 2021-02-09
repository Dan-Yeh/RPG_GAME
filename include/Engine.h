#ifndef ENGINE_H
#define ENGINE_H

#include "Trainee.h"
#include "Mage.h"
#include "Fighter.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#define DIR_PATH "./saves/"

class Engine {
private:
    std::string file_name;
    unsigned int in_game_day = 0;

public:
    Engine() = default;
    Engine(std::string name);

    std::unique_ptr<Trainee> player;
    std::unique_ptr<Trainee> create_player(std::ifstream &file);
    std::unique_ptr<Trainee> create_player(std::string n, unsigned int hp, unsigned int type_id);

    void save(void);
    void load(void);
    void rest(void);
    void show(void);
    void level_up(void);
    void choose_profession(void);
};

#endif

