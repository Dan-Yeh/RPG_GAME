#include "../include/Characters.h"

BaseCharacter::BaseCharacter(std::string n, unsigned int hp)
{
    name = n;
    HP = (hp > HP) ? HP : hp;
}

BaseCharacter::BaseCharacter(std::ifstream& file)
{   
    file >> name
        >> HP
        >> max_HP
        >> attack_pts
        >> defense_pts;
}

std::string BaseCharacter::get_name(void) const { return name; }

unsigned int BaseCharacter::get_maxHP(void) const { return max_HP; }

unsigned int BaseCharacter::get_HP(void) const { return HP; }

unsigned int BaseCharacter::get_defense_pts(void) const { return defense_pts; }

void BaseCharacter::show_status(void)
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Current HP is " << HP << std::endl;
    std::cout << "Attack points: " << attack_pts << std::endl;
    std::cout << "Defense points: " << defense_pts << std::endl;
}

void BaseCharacter::sub_HP(unsigned int lose)
{
    HP = (lose > HP) ? 0 : (HP - lose);
}

bool BaseCharacter::isAlive(void) { return (HP > 0); }
