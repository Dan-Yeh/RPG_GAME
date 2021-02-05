#ifndef FIGHTER_H
#define FIGHTER_H

#include "Trainee.h"

class Fighter: public Trainee {
private:

public:
    Fighter(std::string n = "default", unsigned int hp = 20);
    std::string get_name(void) const;
};

#endif
