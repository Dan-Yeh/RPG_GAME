#ifndef UTILITY_H
#define UTILITY_H

#include "Fighter.h"
#include "Mage.h"
#include "Trainee.h"
#include <memory>
using namespace CharacterFactory;

namespace CharacterFactory {

void save(std::string file_name, std::unique_ptr<Trainee>&, unsigned int);
std::tuple<std::unique_ptr<Trainee>, unsigned int> load(std::string);
std::unique_ptr<Trainee> choose_profession(std::unique_ptr<Trainee> &player);
std::unique_ptr<Trainee> create_player(std::ifstream&);
std::unique_ptr<Trainee> create_player(std::unique_ptr<Trainee>&, unsigned int);

}

#endif
