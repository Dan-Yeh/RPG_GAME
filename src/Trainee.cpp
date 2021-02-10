#include "../include/Trainee.h"
#include <fstream>

void Trainee::save(std::ofstream& out_file) const
{
    out_file << type_id << std::endl
             << name << std::endl
             << level << std::endl
             << HP << std::endl
             << max_HP << std::endl
             << attack_pts << std::endl
             << defense_pts << std::endl;
}

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
    HP = max_HP;
    std::cout << "LEVEL UP!!!" << std::endl;
    std::cout << "Your status now" << std ::endl;
    show_status();
    if (level == transfer_level) { return true; }
    return false;
}
