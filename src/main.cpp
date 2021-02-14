//TODO: add test
#include "../include/Game.h"
#include <fstream>
#include <memory>

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
    }
#else
    if (game.initialization() == true) 
        game.game_loop();
#endif
    return 0;
}
