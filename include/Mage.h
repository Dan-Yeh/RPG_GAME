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
    unsigned int mana = 30;
    unsigned int max_mana = 30;
    unsigned int magic = 7;
    unsigned int magic_threshold = 5;
    unsigned int mp_consumption = 2;
    
public:
    Mage(Trainee &trainee) : Trainee(trainee){
        class_name = "Mage";
        type_id = 3;
    };
    Mage(std::ifstream &file) : Trainee(file){
        file >> mana
            >> max_mana
            >> magic;

        class_name = "Mage";
        type_id = 3;
    };

    // override methods
    unsigned int attack(void) override;
    void save(std::ofstream &out_file) const override;
    void rest(void) override;
    void show_status(void) const override;
    bool level_up(void) override;
};

#endif
