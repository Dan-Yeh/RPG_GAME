//TODO: add test
#include "../include/Game.h"
#include <fstream>
#include <memory>

void fight(Game& game);

int main()
{
    Game game;
    bool quit_game;

    quit_game = game.initialization();
    if(quit_game) { return 0;}

    game.game_loop();
    
    return 0;
}
