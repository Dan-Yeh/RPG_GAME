#include "../include/Fighter.h"
#include <cstdlib>

unsigned int Fighter::attack(void) 
{
    /* initialize random seed: */
    srand(time(NULL));
    float times = ((double) rand() / (RAND_MAX)) > prob_threshold ? 1.5 : 1;
    if (times == 1.5)
        std::cout << "Strike!!!\n";
    return get_attack_pts() * times;
    //TODO: float -> integer implicit conversion issue
}

bool Fighter::level_up()
{
    level++;
    max_HP += 3;
    attack_pts += 3;
    defense_pts += 2;
    std::cout << "\nLEVEL UP!!!" << std::endl;
    std::cout << "Your status now" << std ::endl;
    show_status();
    return false;
}

unsigned int Fighter::get_type_id(void) const { return type_id; }

std::string Fighter::get_class_name(void) const { return class_name; }

unsigned int Fighter::get_maxHP(void) const { return max_HP; }

unsigned int Fighter::get_HP(void) const { return HP; }

unsigned int Fighter::get_attack_pts(void) const { return attack_pts; }

unsigned int Fighter::get_defense_pts(void) const { return defense_pts; }

unsigned int Fighter::get_level(void) const { return level; }
