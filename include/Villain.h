#ifndef VILLAIN_H
#define VILLAIN_H

#include "Characters.h"

class Villain: public BaseCharacter {
private:

public:
    Villain(std::string n = "default", unsigned int hp = 20);
    std::string get_name(void) const;
};

#endif
