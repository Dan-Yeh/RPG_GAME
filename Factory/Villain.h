#ifndef VILLAIN_H
#define VILLAIN_H

#include "Characters.h"
#include "../Utilities/utils.h"

/**
 * Class inherited from BaseCharacter
 * 
 * Implement random variable generator for generating Villains
 *
 * */

class Villain : public CharacterFactory::BaseCharacter {
public:
    Villain(std::string n = "Villain", unsigned int hp = 20)
        : BaseCharacter(n, hp)
    {
        class_name = "Villain";
        type_id = 4;
        /* Random generate skill points*/
        unsigned int num =  RNG::roll_dice() * 5 + 1;
        name += std::string(num, 'V');
        HP = HP / 3 + num;
        max_HP = max_HP / 3 + num;
        attack_pts = attack_pts / 3 + num;
        //defense_pts += num;
        level += num;
    }
};
#endif
