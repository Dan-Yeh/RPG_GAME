#ifndef GAME_H
#define GAME_H

#include "../Factory/Characters.h"
#include "Bot.h"
#include "Engine.h"
#include <sstream>

/**
 * Class for game logic and menu.
 * 
 * */

class Game {
private:
    char init_status;
    std::string action; 
    Engine engine;
    //Bot and iss for demo
    Bot bot;
    std::istringstream iss;

    void menu();
    void behavior_options();

public:
    Game();
    bool initialization();
    void game_loop();
};

#endif
