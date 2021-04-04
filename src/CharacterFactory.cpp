#include "../Factory/CharacterFactory.h"
#include "../Factory/Mage.h"
#include <memory>
#include <sstream>
#include <string>
#include <utility>

using namespace CharacterFactory;

std::string CharacterFactory::serialize(std::unique_ptr<Trainee>& player)
{
    unsigned int type_id = player->get_type_id();
    std::stringstream player_info;
    if (type_id != 3) {
        player_info << type_id << ";"
                    << player->get_name() << ";"
                    << player->get_level() << ";"
                    << player->get_HP() << ";"
                    << player->get_maxHP() << ";"
                    << player->get_attack_pts() << ";"
                    << player->get_defense_pts() << std::endl;
    } else {
        Mage* mage;
        mage = dynamic_cast<Mage*>(player.get());
        player_info << type_id << ";"
                    << mage->get_name() << ";"
                    << mage->get_level() << ";"
                    << mage->get_HP() << ";"
                    << mage->get_maxHP() << ";"
                    << mage->get_attack_pts() << ";"
                    << mage->get_defense_pts() << ";"
                    << mage->get_mana() << ";"
                    << mage->get_max_mana() << ";"
                    << mage->get_magic_pts() << std::endl;
    }
    return player_info.str();
}

std::vector<std::string> CharacterFactory::deserialize(std::string player_info)
{
    std::vector<std::string> members;
    std::stringstream s_stream(player_info);
    while (s_stream.good()) {
        std::string substr;
        getline(s_stream, substr, ';');
        members.push_back(substr);
    }
    return members;
}

std::unique_ptr<Trainee> CharacterFactory::choose_profession(std::unique_ptr<Trainee>& player)
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

std::unique_ptr<Trainee> CharacterFactory::create_player(std::vector<std::string>& members)
{
    unsigned int type_id;
    type_id = std::stoi(members.at(0));
    switch (type_id) {
    case 1:
        return std::make_unique<Trainee>(members);
    case 2:
        return std::make_unique<Fighter>(members);
    case 3:
        return std::make_unique<Mage>(members);
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
