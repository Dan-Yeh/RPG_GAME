#include "../include/Fighter.h"
#include <cstdlib>

unsigned int Fighter::attack(void) 
{
    /* initialize random seed: */
    srand(time(NULL));
    float times = rand() > prob_threshold ? 1.5 : 1;
    return get_attack_pts() * times;
    //TODO: float -> integer implicit conversion issue
}

bool Fighter::level_up()
{
    level++;
    max_HP += 3;
    attack_pts += 3;
    defense_pts += 2;
    HP = max_HP;
    std::cout << "LEVEL UP!!!" << std::endl;
    std::cout << "Your status now" << std ::endl;
    show_status();
    return false;
}
