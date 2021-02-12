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
    const std::string class_name = "Villain";
public:
    Villain(std::string n = "Villain", unsigned int hp = 20)
        : BaseCharacter(n, hp)
    {
        /* Random generate skill points*/
        // srand(time(NULL));
        // unsigned int num = rand() * 10 + 1;
        // name += std::string(num, 'V');
        // HP += num;
        // max_HP += num;
        // attack_pts += num;
        // defense_pts += num;
        // level += num;
    }
};

#endif
