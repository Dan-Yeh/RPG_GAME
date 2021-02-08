#ifndef VILLAIN_H
#define VILLAIN_H

#include "Characters.h"
#include <random>
#include <time.h>

class Villain : public BaseCharacter {
public:
    Villain(std::string n = "Villain") : BaseCharacter(n)
    {
        /* Random generate skill points*/
        srand(time(NULL));
        unsigned int num = rand() * 10 + 1;
        name += std::string(num, 'V');
        HP += num;
        max_HP += num;
        attack_pts += num;
        defense_pts += num;
        level += num;
    }
};

#endif
