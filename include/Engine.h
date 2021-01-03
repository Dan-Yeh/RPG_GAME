//TODO desstructor to autosave file
#ifndef ENGINE_H
#define ENGINE_H

#include "Characters.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#define DIR_PATH "./saves/"

class Engine {
private:
    std::string file_name;
    unsigned int in_game_day = { 0 };

public:
    std::unique_ptr<BaseCharacter> player;

    Engine() = default;
    Engine(std::string name);
    void save(void);
    void load(void);
    void rest(void);
    void show(void);
};

#endif

