#ifndef BOT_H
#define BOT_H

#include "Engine.h"
#include "../Factory/CharacterFactory.h"

class Bot {
private:
    Engine engine;
    std::string mode;
    std::string file_name;
    std::string commands = "";
    unsigned int type_id;
    unsigned int loop_times = 6;
    
    void menu();
    void run_demo();
    bool fight();
    void rest();
    void show();
    void save();

public:
    Bot();
    void select_demo();
};

#endif