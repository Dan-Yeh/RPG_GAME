#include "../include/Engine.h"
#include <cstdlib>
#include <iostream>
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
    std::ofstream out_file(file_name);
    if (out_file.is_open()) {
        player->save(out_file);
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
        player = create_player(file);
    }
}

void Engine::rest(void)
{
    player->rest();
    in_game_day++;
}

void Engine::fight()
{
    std::unique_ptr<Villain> enemy = std::make_unique<Villain>("Gobelin", 15);
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
        choose_profession();
}

void Engine::choose_profession(void)
{
    std::cout << "Congrats! Your are now able to choose a profession." << std::endl;
    std::cout << "Press 2 if you want to be a Fighter." << std::endl;
    std::cout << "Press 3 if you want to be a Mage." << std::endl;
    char type_id;
    while (true) {
        std::cin >> type_id;
        if (std::isdigit(type_id))
            break;
        else
            std::cout << "Please type digits!" << std::endl;
    }
    unsigned int type_ID = static_cast<unsigned int>(type_id - '0');
    player = create_player(type_ID);
}

//TODO:Template?
std::unique_ptr<Trainee> Engine::create_player(std::ifstream &file)
{
    unsigned int type_id;
    file >> type_id;
    switch (type_id) {
    case 1:
        return std::make_unique<Trainee>(file);
    case 2:
        return std::make_unique<Fighter>(file);
    case 3:
        return std::make_unique<Mage>(file);
    default:
        std::cout << "Wrong ID! Please restart the game." << std::endl;
        break;
    }
    return nullptr;
}

//TODO:Template?
std::unique_ptr<Trainee> Engine::create_player(unsigned int type_id)
{
    switch (type_id) {
    case 1:
        std::cout << "Stay as a Trainee.\n";
        return std::make_unique<Trainee>(*player);
    case 2:
        std::cout << "Transfer into a Fighter!!!\n";
        return std::make_unique<Fighter>(*player);
    case 3:
        std::cout << "Transfer into a Mage!!!\n";
        return std::make_unique<Mage>(*player);
    default:
        std::cout << "Wrong ID! Please restart the game." << std::endl;
        break;
    }
    return nullptr;
}
