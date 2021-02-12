#ifndef GAME_H
#define GAME_H

#include "Engine.h"

/**
 * Class for game logic and menu.
 * 
 * */

class Game {
private:
    char init_status;
    std::string action;
    Engine engine;

    void menu();
    void behavior_options();

public:
    Game();
    bool initialization();
    void game_loop();
};

#endif
