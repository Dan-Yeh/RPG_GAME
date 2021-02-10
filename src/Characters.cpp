#include "../include/Characters.h"

BaseCharacter::BaseCharacter(std::string n, unsigned int hp)
{
    name = n;
    HP = (hp > HP) ? HP : hp;
}

BaseCharacter::BaseCharacter(std::ifstream &file)
{
    file >> name
        >> level
        >> HP
        >> max_HP
        >> attack_pts
        >> defense_pts;
}

std::string BaseCharacter::get_name(void) const { return name; }

unsigned int BaseCharacter::get_type_id(void) const { return type_id; }

unsigned int BaseCharacter::get_maxHP(void) const { return max_HP; }

unsigned int BaseCharacter::get_HP(void) const { return HP; }

unsigned int BaseCharacter::get_attack_pts(void) const { return attack_pts; }

unsigned int BaseCharacter::get_defense_pts(void) const { return defense_pts; }

unsigned int BaseCharacter::get_level(void) const { return level; }

unsigned int BaseCharacter::sub_HP(unsigned int attack_pts, unsigned int defense_pts)
{
    unsigned int lose = attack_pts > defense_pts ? attack_pts-defense_pts : 0;
    HP = (lose > HP) ? 0 : (HP - lose);
    return lose;
}

unsigned int BaseCharacter::defend(void) { return get_defense_pts(); }

bool BaseCharacter::isAlive(void) { return (HP > 0); }

// abstract methods
unsigned int BaseCharacter::attack(void) { return get_attack_pts(); }

void BaseCharacter::show_status(void) const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Current HP is " << HP << std::endl;
    std::cout << "Attack points: " << attack_pts << std::endl;
    std::cout << "Defense points: " << defense_pts << std::endl;
}