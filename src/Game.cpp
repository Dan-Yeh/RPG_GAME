#include "../include/Game.h"
#include "../Factory/Trainee.h"
#include "../Factory/Villain.h"
#include "../include/Engine.h"
#include <iostream>

Game::Game()
{
    menu();
}

void Game::menu()
{
    /*Initailize*/
    std::cout << "***********************************\n";
    std::cout << "*      Welcome to RPG game!!!     *\n";
    std::cout << "*  For playing New Game, enter n. *\n";
    std::cout << "*  For playing Old Game, enter o. *\n";
    std::cout << "*      For Game Demo, enter d.    *\n";
    std::cout << "*  If you want to Exit, enter q.  *\n";
    std::cout << "***********************************\n";
}

void Game::behavior_options()
{
    std::cout << "****************************************\n";
    std::cout << "*            Game Instructions         *\n";
    std::cout << "*          To fight, enter fight.      *\n";
    std::cout << "*      To heal player, enter rest.     *\n";
    std::cout << "*  To show current status, enter show. *\n";
    std::cout << "*  To save current status, enter save. *\n";
    std::cout << "*      If you want to Exit, enter q.   *\n";
    std::cout << "****************************************\n";
}

bool Game::initialization()
{
    bool init = true;
    while (true) {
        std::cin >> init_status;
        if (init_status == 'n') {
            std::string character_name;
            std::cout << "Please input a character name: " << std::endl;
            std::cin >> character_name;
            engine = Engine(character_name);
            break;
        } else if (init_status == 'o') {
            std::string character_name;
            std::cout << "Please input a character name(also is your file name): " << std::endl;
            std::cin >> character_name;
            engine = Engine(character_name);
            engine.load();
            break;
        } else if (init_status == 'd') {
            std::cout << "*****Welcome to Demo Mode!!!*****\n";
            std::string behavior = "n Dan";
            std::istringstream iss(behavior);
            std::cin.rdbuf(iss.rdbuf());
            bot_flag = true;
            continue;
        } else if (init_status == 'q') {
            init = false; // would skip game logic
            break;
        } else
            std::cout << "Invalid Input! Please Try again!\n";
    }

    return init;
}

void Game::game_loop()
{
    if (bot_flag) {
        std::string behavior = bot.behavior_f1;
        std::istringstream iss(behavior);
        std::cin.rdbuf(iss.rdbuf());
    }
    /*Playing game*/
    while (engine.player->isAlive()) {
        behavior_options();
        std::cin >> action;
        if (action == "fight") {
            engine.fight();
            continue;
        } else if (action == "rest") {
            engine.rest();
            continue;
        } else if (action == "show") {
            engine.show();
            continue;
        } else if (action == "save") {
            engine.save();
            std::cout << "Successfully Saved!\n";
            continue;
        } else if (action == "q") {
            // auto save when exit game loop
            engine.save();
            break;
        } else {
            std::cout << "Invalid Input! Please Try again!\n";
        }
    }

    if (!engine.player->isAlive()) {
        std::cout << "You died!\n";
    }
}
