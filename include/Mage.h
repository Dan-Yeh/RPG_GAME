#ifndef MAGE_H
#define MAGE_H

#include "Trainee.h"

class Mage: public Trainee{
private:
    unsigned int type_id = 3;
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
    unsigned int attack(void) override;
    void save(std::ofstream &out_file) const override;
    void rest(void) override;
    void show_status(void) const override;
    bool level_up(void) override;
};

#endif
