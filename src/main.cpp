//TODO: add test
#include "../include/Game.h"
#include <fstream>
#include <memory>

int main()
{
    Game game;

    if (game.initialization() == true) 
        game.game_loop();

    return 0;
}
