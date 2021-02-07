#ifndef VILLAIN_H
#define VILLAIN_H

#include "Characters.h"

class Villain: public BaseCharacter {
public:
    Villain(std::string n = "default", unsigned int hp = 20) : BaseCharacter(n, hp) {}
    std::string get_name(void) const {return name;}
};

#endif
