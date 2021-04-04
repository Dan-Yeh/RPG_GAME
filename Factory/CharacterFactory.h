#ifndef UTILITY_H
#define UTILITY_H

#include "Fighter.h"
#include "Mage.h"
#include "Trainee.h"
#include <memory>
#include <string>
using namespace CharacterFactory;

namespace CharacterFactory {

std::string serialize(std::unique_ptr<Trainee>&);
std::vector<std::string> deserialize(std::string player_info);
std::unique_ptr<Trainee> choose_profession(std::unique_ptr<Trainee> &player);
std::unique_ptr<Trainee> create_player(std::vector<std::string>&);
std::unique_ptr<Trainee> create_player(std::unique_ptr<Trainee>&, unsigned int);

}

#endif
