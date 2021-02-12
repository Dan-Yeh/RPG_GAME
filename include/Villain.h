#ifndef VILLAIN_H
#define VILLAIN_H

/**
 * Class inherited from BaseCharacter
 * 
 * Implement random variable generator for generating Villains
 *
 * */
#include "Characters.h"
#include <random>
#include <time.h>

class Villain : public BaseCharacter {
private:
    std::string class_name = "Villain";

public:
    Villain(std::string n = "Villain", unsigned int hp = 20)
        : BaseCharacter(n, hp)
    {
        /* Random generate skill points*/
        srand(time(0));
        unsigned int num = ((double) rand() / (RAND_MAX))*5 + 1;
        name += std::string(num, 'V');
        HP = HP/2 + num;
        max_HP = max_HP/2 + num;
        attack_pts = attack_pts/2 + num;
        //defense_pts += num;
        level += num;
    }
};

#endif
