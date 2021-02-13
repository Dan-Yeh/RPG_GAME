#include "../include/Engine.h"
#include <cstdlib>
#include <iostream>
#include <istream>
#include <memory>
#include <string>

Engine::Engine(std::string name)
{
    in_game_day = 0;
    file_name = DIR_PATH + name + ".txt";
    player = std::make_unique<Trainee>(name);
}

void Engine::save(void)
{
    std::ofstream out_file(file_name);
    if (out_file.is_open()) {
        out_file << in_game_day << std::endl;
        out_file << CharacterFactory::serialize(player); 
        out_file.close();
    } else {
        std::cout << "Cannot open the File.\n";
        std::cout << "Probably at wrong directory.\n";
    }
}

void Engine::load(void)
{
    std::ifstream file(file_name);
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "The record is empty! Start a new game with this name.\n";
    } else {
        std::string player_info;
        std::vector<std::string> members;
        file >> in_game_day;
        file >> player_info;
        members = CharacterFactory::deserialize(player_info);
        std::unique_ptr<Trainee> player = CharacterFactory::create_player(members);
    }
}

void Engine::rest(void)
{
    player->rest();
    in_game_day++;
}

void Engine::fight()
{
    std::unique_ptr<CharacterFactory::Villain> enemy = std::make_unique<CharacterFactory::Villain>("Gobelin", 15);
    std::cout << "\nA Gobelin appears\n";
    enemy->show_status();
    unsigned int player_sub_HP, enemy_sub_HP;
    while (true) {
        player_sub_HP = player->sub_HP(enemy->attack(),player->defend());
        std::cout << "\nYou've been attack! Lose " << player_sub_HP << " hp.";
        std::cout << "\tCurrent hp: " << player->get_HP() << std::endl;
        if (!player->isAlive()) {
            std::cout << "You're defeated!\n";
            break;
        }
        enemy_sub_HP = enemy->sub_HP(player->attack(),enemy->defend());
        std::cout << "Fight back! The Gobelin loses " << enemy_sub_HP << " hp.\n";
        if (!enemy->isAlive()) {
            std::string n = enemy->get_name();
            std::cout << "The " << n << " is dead! You win!\n";
            level_up();
            break;
        }
    }
    in_game_day++;
}

void Engine::show(void)
{
    std::cout << "In game day is: " << in_game_day << " days.\n";
    player->show_status();
}

void Engine::level_up(void)
{
    if (player->level_up())
        player = CharacterFactory::choose_profession(player);
}

