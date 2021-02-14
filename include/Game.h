#ifndef GAME_H
#define GAME_H

#include "../Factory/Characters.h"
#include "Bot.h"
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
    Bot bot;
    bool bot_flag = false;

    void menu();
    void behavior_options();

public:
    Game();
    bool initialization();
    void game_loop();
};

#endif
