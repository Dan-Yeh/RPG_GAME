#include "../Factory/Fighter.h"

unsigned int Fighter::attack(void) 
{
    float prob = RNG::roll_dice();
    float times = prob > prob_threshold ? 1.5 : 1;
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

