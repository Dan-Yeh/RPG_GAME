#include "../include/Characters.h"
#include "../include/Game.h"

Game::Game(std::string name)
{
    file_name = DIR_PATH + name + ".txt";
    player = std::make_unique<BaseCharacter>(name);
}

void Game::save(void)
{
    std::ofstream out_file(file_name);
    if (out_file.is_open()) {
        out_file << player->get_name() << std::endl
                 << player->get_HP() << std::endl
                 << player->get_maxHP() << std::endl
                 << player->get_attack_pts() << std::endl
                 << player->get_defense_pts() << std::endl
                 << player->get_in_game_day() << std::endl;
        out_file.close();
    } else {
        std::cout << "Cannot open the File.\n";
    }
}

void Game::load(void)
{
    std::unique_ptr<BaseCharacter> player;
    std::ifstream file(file_name);
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "The record is empty! Start a new game with this name.\n";
    } else {
        player = std::make_unique<BaseCharacter>(file);
    }
}

//\std::ostream& operator<<(std::ostream& out, BaseCharacter& player)
//\{
//\    out << player.get_name() << std::endl
//\        << player.get_HP() << std::endl
//\        << player.get_maxHP() << std::endl
//\        << player.get_attack_pts() << std::endl
//\        << player.get_defense_pts() << std::endl
//\        << player.get_in_game_day() << std::endl;
//\    return out;
//\}
