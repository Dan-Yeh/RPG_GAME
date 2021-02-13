#include "../include/Bot.h"

Bot::Bot() {
    
}

void Bot::menu()
{
    /*Initailize*/
    std::cout << "******************************************\n";
    std::cout << "*         Welcome to Demo Mode!!!        *\n";
    std::cout << "*  For demo of being a Fighter, enter f. *\n";
    std::cout << "*  For demo of being a Mage, enter m.    *\n";
    std::cout << "*  If you want to Exit demo, enter q.    *\n";
    std::cout << "******************************************\n";
}

void Bot::select_demo() {
    while(true) {
        menu();
        std::cin >> mode;
        if(mode == "f") {
            type_id = 2;
            file_name = "FighterDemo";
            run_demo();
            continue;
        } else if(mode == "m") {
            type_id = 3;
            file_name = "MageDemo";
            run_demo();
            continue;
        } else if(mode == "q") {
            break;
        } else {
            std::cout << "Invalid Input! Please Try again!\n";
        }
    }
    
}

void Bot::run_demo() {
    // Commands used in demo
    engine = Engine(file_name);
    show();
    for(unsigned int i=0; i<loop_times; i++) {
        if(fight() == true) {
            engine.player =  CharacterFactory::create_player(engine.player, type_id);
        }
        rest();   
        std::cout <<  std::endl; 
        show();
    }
    save();
    
    // print commands to terminal
    std::cout << "\nSequence of commands used in the demo: " << std::endl;
    std::cout << commands;

    // clear the commands for next demo
    commands = "";
}

bool Bot::fight() {
    std::unique_ptr<Villain> enemy = std::make_unique<Villain>("Gobelin", 15);
    std::cout << "\nA Gobelin appears\n";
    enemy->show_status();
    unsigned int player_sub_HP, enemy_sub_HP;
    bool transfer = false;
    while (true) {
        player_sub_HP = engine.player->sub_HP(enemy->attack(), engine.player->defend());
        std::cout << "\nYou've been attack! Lose " << player_sub_HP << " hp.";
        std::cout << "\tCurrent hp: " << engine.player->get_HP() << std::endl;
        if (!engine.player->isAlive()) {
            std::cout << "You're defeated!\n";
            break;
        }
        enemy_sub_HP = enemy->sub_HP(engine.player->attack(), enemy->defend());
        std::cout << "Fight back! The Gobelin loses " << enemy_sub_HP << " hp.\n";
        if (!enemy->isAlive()) {
            std::string n = enemy->get_name();
            std::cout << "The " << n << " is dead! You win!\n";
            transfer = engine.player->level_up();
            break;
        }
    }
    engine.in_game_day++;
    commands += "fight->";
    return transfer;
}

void Bot::rest() {
    engine.rest();
    commands += "rest->";
}

void Bot::show() {
    engine.show();
    commands += "show->";
}

void Bot::save() {
    engine.save();
    commands += "save.\n";
}