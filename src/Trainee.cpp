#include "../Factory/Trainee.h"
#include <fstream>
#include <sstream>
#include <string>

void Trainee::rest(void)
{
    HP = max_HP;
    std::cout << "Rest to restore HP!" << std::endl;
}

bool Trainee::level_up(void)
{
    level++;
    max_HP++;
    attack_pts++;
    defense_pts++;
    std::cout << "\nLEVEL UP!!!" << std::endl;
    std::cout << "Your status now" << std ::endl;
    show_status();
    if (level == transfer_level) { return true; }
    return false;
}
