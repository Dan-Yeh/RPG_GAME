//TODO: add test
#include "../include/Characters.h"
#include "../include/Game.h"
#include <fstream>
#include <memory>

void fight(Game& game);

int main()
{
    char init_status;
    std::string action;
    Game game;

    /*Initailize*/
    std::cout << "***********************************\n";
    std::cout << "*      Welcome to RPG game!!!     *\n";
    std::cout << "*  For playing New Game, enter n. *\n";
    std::cout << "*  For playing Old Game, enter o. *\n";
    std::cout << "*  If you want to Exit, enter q.  *\n";
    std::cout << "***********************************\n";

    while (true) {
        std::cin >> init_status;
        if (init_status == 'n') {
            std::string character_name;
            std::cout << "Please input a character name: " << std::endl;
            std::cin >> character_name;
            game = Game(character_name);
            break;
        } else if (init_status == 'o') {
            std::string character_name;
            std::cout << "Please input a character name(also is your file name): " << std::endl;
            std::cin >> character_name;
            game = Game(character_name);
            game.load();
            break;
        } else if (init_status == 'q') {
            goto End; // would skip game logic
        } else
            std::cout << "Invalid Input! Please Try again!\n";
    }

    std::cout << "****************************************\n";
    std::cout << "*            Game Instructions         *\n";
    std::cout << "*          To fight, enter fight.      *\n";
    std::cout << "*  To show current status, enter show. *\n";
    std::cout << "*  To save current status, enter save. *\n";
    std::cout << "*      If you want to Exit, enter q.   *\n";
    std::cout << "****************************************\n";

    /*Playing game*/
    while (game.player->isAlive()) {
        std::cin >> action;
        if (action == "fight") {
            fight(game);
            continue;
        } else if (action == "rest") {
            game.rest();
            continue;
        } else if (action == "show") {
            game.show();
            continue;
        } else if (action == "save") {
            game.save();
            std::cout << "Successfully Saved!\n";
            continue;
        } else if (action == "q") {
            // auto save when exit game loop
            game.save();
            break;
        } else {
            std::cout << "Invalid Input! Please Try again!\n";
        }
    }

    if (!game.player->isAlive()) {
        std::cout << "You died!\n";
    }

End:
    return 0;
}

void fight(Game& game)
{
    std::cout << "A Gobelin appears\n";
    std::unique_ptr<BaseCharacter> enemy = std::make_unique<BaseCharacter>("Gobelin", 15);
    while (true) {
        std::cout << "You've been attack! Lose " << enemy->get_attack_pts() << "hp.\n";
        std::cout << "Fight back! The Gobelin lose " << game.player->get_attack_pts() << " hp.\n";
        game.player->sub_HP(enemy->get_attack_pts());
        enemy->sub_HP(game.player->get_attack_pts());
        if (!enemy->isAlive()) {
            std::string n = enemy->get_name();
            std::cout << "The " << n << " is dead! You win!\n";
            break;
        }
        if (!game.player->isAlive()) {
            std::cout << "You're defeated!\n";
            break;
        }
    }
}
