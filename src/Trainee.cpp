#include "../Factory/Trainee.h"
#include <fstream>

using namespace CharacterFactory;

void Trainee::save(std::ofstream& out_file) const
{
    out_file << get_type_id() << std::endl
             << name << std::endl
             << get_level() << std::endl
             << get_HP() << std::endl
             << get_maxHP() << std::endl
             << get_attack_pts() << std::endl
             << get_defense_pts() << std::endl;
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


