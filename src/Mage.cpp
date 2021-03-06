#include "../Factory/Mage.h"

using namespace CharacterFactory;

unsigned int Mage::attack(void)
{
    if (mana >= magic_threshold) {
        mana -= mp_consumption;
        std::cout << "Expecto patronum!!!" << std::endl;
        return magic;
    } else
        return get_attack_pts();
}

void Mage::rest(void)
{
    HP = max_HP;
    mana = max_mana;
    std::cout << "Rest to restore HP and mana!" << std::endl;
}

void Mage::show_status(void) const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Profession: " << get_class_name() << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Current HP is " << HP << std::endl;
    std::cout << "Current Mana is " << mana << std::endl;
    std::cout << "Attack points: " << attack_pts << std::endl;
    std::cout << "Magic attack points: " << magic << std::endl;
    std::cout << "Defense points: " << defense_pts << std::endl;
}

bool Mage::level_up()
{
    level++;
    max_HP++;
    max_mana += 2;
    attack_pts++;
    magic += 3;
    defense_pts++;
    std::cout << "\nLEVEL UP!!!" << std::endl;
    std::cout << "Your status now" << std ::endl;
    show_status();
    return false;
}

unsigned int Mage::get_mana(void) { return mana; }
unsigned int Mage::get_max_mana(void) { return max_mana; }
unsigned int Mage::get_magic_pts(void) { return magic; }
