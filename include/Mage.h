#ifndef MAGE_H
#define MAGE_H

/**
 * Class inherited from Trainee.
 * 
 * Implement magicversion of attack.
 *
 * */
#include "Trainee.h"

class Mage: public Trainee{
private:
    const unsigned int type_id = 3;
    std::string class_name = "Mage";
    unsigned int level = 5;
    unsigned int mana = 30;
    unsigned int max_mana = 30;
    unsigned int magic = 7;
    unsigned int magic_threshold = 5;
    unsigned int mp_consumption = 2;
    
public:
    Mage(std::string n, unsigned int hp) : Trainee(n, hp){};
    Mage(std::ifstream &file) : Trainee(file){
        file >> mana
            >> max_mana
            >> magic;
    };

    // override methods
    std::string get_class_name(void) const override;
    unsigned int get_type_id(void) const override;
    unsigned int get_maxHP(void) const override;
    unsigned int get_HP(void) const override ;
    unsigned int get_attack_pts(void) const override;
    unsigned int get_defense_pts(void) const override;
    unsigned int get_level(void) const override;
    unsigned int attack(void) override;
    void save(std::ofstream &out_file) const override;
    void rest(void) override;
    void show_status(void) const override;
    bool level_up(void) override;
};

#endif
