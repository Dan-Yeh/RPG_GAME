#include "../include/Characters.h"
#include "../include/Engine.h"
#include "../include/Game.h"


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
    bool quit = false;
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
        } else if (init_status == 'q') {
            quit = true; // would skip game logic
        } else
            std::cout << "Invalid Input! Please Try again!\n";
    }

    return quit;
}

void Game::game_loop()
{
    /*Playing game*/
    behavior_options();
    while (engine.player->isAlive()) {
        std::cin >> action;
        if (action == "fight") {
            fight(engine);
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

void Game::fight(Engine& engine)
{
    std::cout << "A Gobelin appears\n";
    std::unique_ptr<BaseCharacter> enemy = std::make_unique<BaseCharacter>("Gobelin", 15);
    while (true) {
        std::cout << "You've been attack! Lose " << enemy->get_attack_pts() << "hp.\n";
        std::cout << "Fight back! The Gobelin lose " << engine.player->get_attack_pts() << " hp.\n";
        engine.player->sub_HP(enemy->get_attack_pts());
        enemy->sub_HP(engine.player->get_attack_pts());
        if (!enemy->isAlive()) {
            std::string n = enemy->get_name();
            std::cout << "The " << n << " is dead! You win!\n";
            break;
        }
        if (!engine.player->isAlive()) {
            std::cout << "You're defeated!\n";
            break;
        }
    }
}