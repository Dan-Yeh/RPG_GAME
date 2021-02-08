//TODO desstructor to autosave file
#ifndef ENGINE_H
#define ENGINE_H

#include "Trainee.h"
#include "Mage.h"
#include "Fighter.h"
#include <fstream>
#include <iostream>
#include <istream>
#include <memory>
#include <string>

#define DIR_PATH "./saves/"

class Engine {
private:
    std::string file_name;
    unsigned int in_game_day = 0;
public:
    std::unique_ptr<Trainee> player;
    std::unique_ptr<Trainee> create_player(std::istream file);

    Engine() = default;
    Engine(std::string name);
    void save(void);
    void load(void);
    void rest(void);
    void show(void);
};

#endif

