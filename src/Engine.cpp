#include "../include/Engine.h"
#include <cstdlib>
#include <iostream>
#include <istream>
#include <memory>

Engine::Engine(std::string name)
{
    in_game_day = 0;
    file_name = DIR_PATH + name + ".txt";
    player = std::make_unique<CharacterFactory::Trainee>(name);
}

void Engine::save(void)
{
    CharacterFactory::save(file_name, player);
}

void Engine::load(void)
{
    player = CharacterFactory::load(file_name);
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

