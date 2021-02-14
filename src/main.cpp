//TODO: add test
#include "../include/Game.h"
#include <fstream>
#include <memory>
#include <chrono>
#include <thread>
#include <unistd.h>

int main()
{
    Game game;

#ifdef TEST
    unsigned int i = 0;
    unsigned int loop_num = game.bot.behaviors.size();
    while (i < loop_num) {
        game.initialization(i);
        game.game_loop();
        i++;
        sleep(5);
    }
#else
    if (game.initialization() == true) 
        game.game_loop();
#endif
    return 0;
}
