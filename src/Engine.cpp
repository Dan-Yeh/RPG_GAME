#include "../include/Characters.h"
#include "../include/Engine.h"

Engine::Engine(std::string name)
{
    in_game_day = 0;
    file_name = DIR_PATH + name + ".txt";
    player = std::make_unique<BaseCharacter>(name);
}

void Engine::save(void)
{
    std::ofstream out_file(file_name);
    if (out_file.is_open()) {
        out_file << player->get_name() << std::endl
                 << player->get_HP() << std::endl
                 << player->get_maxHP() << std::endl
                 << player->get_attack_pts() << std::endl
                 << player->get_defense_pts() << std::endl;
        out_file.close();
    } else {
        std::cout << "Cannot open the File.\n";
    }
}

void Engine::load(void)
{
    std::ifstream file(file_name);
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "The record is empty! Start a new game with this name.\n";
    } else {
        player = std::make_unique<BaseCharacter>(file);
    }
}

void Engine::rest(void){
    in_game_day++;
    player->rest();
}

void Engine::show(void) {
    std::cout << "In game day is: " << in_game_day << " days.\n";
    player->show_status();
}
