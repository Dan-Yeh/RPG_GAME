//TODO desstructor to autosave file
#ifndef GAME_H
#define GAME_H

#include "Characters.h"
#include "Engine.h"

class Game {
private:
    char init_status;
    std::string action;
    Engine engine;

    void menu();
    void behavior_options();
    void fight(Engine& engine);

public:
    Game();
    bool initialization();
    void game_loop();
};

#endif
