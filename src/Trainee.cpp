#include "../include/Trainee.h"
#include <fstream>

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
    std::cout << "LEVEL UP!!!" << std::endl;
    std::cout << "Your status now" << std ::endl;
    show_status();
    if (level == transfer_level) { return true; }
    return false;
}

void Trainee::show_status(void) const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Profession: " << get_class_name()<< std::endl;
    std::cout << "Level: " << get_level() << std::endl;
    std::cout << "Current HP is " << get_HP() << std::endl;
    std::cout << "Attack points: " << get_attack_pts() << std::endl;
    std::cout << "Defense points: " << get_defense_pts() << std::endl;
}


unsigned int Trainee::get_type_id(void) const { return type_id; }

std::string Trainee::get_class_name(void) const { return class_name; }

unsigned int Trainee::get_maxHP(void) const { return max_HP; }

unsigned int Trainee::get_HP(void) const { return HP; }

unsigned int Trainee::get_attack_pts(void) const { return attack_pts; }

unsigned int Trainee::get_defense_pts(void) const { return defense_pts; }

unsigned int Trainee::get_level(void) const { return level; }
