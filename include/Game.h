#ifndef GAME_H
#define GAME_H

/**
 * Class for game logic and menu.
 * 
 * */
#include "Characters.h"
#include "Engine.h"
#include "Bot.h"

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
