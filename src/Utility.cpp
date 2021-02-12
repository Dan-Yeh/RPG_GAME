#include "../Factory/Utility.h"
#include <utility>

using namespace CharacterFactory;

void CharacterFactory::save(std::string file_name, std::unique_ptr<Trainee> &player, unsigned int in_game_day)
{
    std::ofstream out_file(file_name);
    if (out_file.is_open()) {
        out_file << in_game_day;
        player->save(out_file);
        out_file.close();
    } else {
        std::cout << "Cannot open the File.\n";
        std::cout << "Probably at wrong directory.\n";
    }
}

std::tuple<std::unique_ptr<Trainee>, unsigned int> CharacterFactory::load(std::string file_name)
{
    std::ifstream file(file_name);
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "The record is empty! Start a new game with this name.\n";
        return std::make_tuple(nullptr, 0);
    } else {
        unsigned int in_game_day;
        file >> in_game_day; 
        std::unique_ptr<Trainee> player = create_player(file);
        return std::make_tuple(player, in_game_day);
    }
}

std::unique_ptr<Trainee> CharacterFactory::choose_profession(std::unique_ptr<Trainee> &player)
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
    return create_player(player, type_ID);
}

std::unique_ptr<Trainee> CharacterFactory::create_player(std::ifstream& file)
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

std::unique_ptr<Trainee> CharacterFactory::create_player(std::unique_ptr<Trainee>& player, unsigned int type_id)

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
