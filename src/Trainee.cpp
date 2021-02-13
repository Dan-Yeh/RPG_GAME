#include "../Factory/Trainee.h"
#include <fstream>
#include <sstream>
#include <string>

void Trainee::show_status(void) const
{
    std::cout << "Name: " << get_name() << std::endl;
    std::cout << "Profession: " << get_class_name()<< std::endl;
    std::cout << "Level: " << get_level() << std::endl;
    std::cout << "Current HP is " << get_HP() << std::endl;
    std::cout << "Attack points: " << get_attack_pts() << std::endl;
    std::cout << "Defense points: " << get_defense_pts() << std::endl;
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
    std::cout << "\nLEVEL UP!!!" << std::endl;
    std::cout << "Your status now" << std ::endl;
    show_status();
    if (level == transfer_level) { return true; }
    return false;
}
