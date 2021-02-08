#include "../include/Engine.h"
#include "../include/Trainee.h"
#include <cstdlib>
#include <istream>
#include <memory>

Engine::Engine(std::string name)
{
    in_game_day = 0;
    file_name = DIR_PATH + name + ".txt";
    player = std::make_unique<Trainee>(name);
}

void Engine::save(void)
{
//TODO: Mage Save
    std::ofstream out_file(file_name);
    if (out_file.is_open()) {
        out_file << player->get_name() << std::endl
                 << player->get_level() << std::endl
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
        player = std::make_unique<Trainee>(file);
    }
}

void Engine::rest(void)
{
    in_game_day++;
    player->rest();
}

void Engine::show(void)
{
    std::cout << "In game day is: " << in_game_day << " days.\n";
    player->show_status();
}

std::unique_ptr<Trainee> Engine::create_player(std::istream file)
{
//TODO: dynamic_cast
    int line_no = 0;
    std::string str = "";
    while (!file.eof()) {
        ++line_no;
        if (line_no == 2)
            getline(file, str);
    }

    if (line_no > 6) 
        return std::make_unique<Mage>(&file);

    if (std::stoi(str) > 4) 
        return std::make_unique<Fighter>(&file);

    return std::make_unique<Trainee>(&file);
}
