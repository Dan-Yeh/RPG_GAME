#ifndef MAGE_H
#define MAGE_H

#include "Trainee.h"
#include <vector>

/**
 * Class inherited from Trainee.
 * 
 * Implement magicversion of attack.
 *
 * */

class Mage : public Trainee {
private:
    unsigned int mana = 30;
    unsigned int max_mana = 30;
    unsigned int magic = 7;
    unsigned int magic_threshold = 5;
    unsigned int mp_consumption = 2;

public:
    Mage(Trainee& trainee)
        : Trainee(trainee)
    {
        class_name = "Mage";
        type_id = 3;
    };
    Mage(std::vector<std::string>& members)
        : Trainee(members)
    {
        class_name = "Mage";
        mana = std::stoi(members.at(7));
        max_mana = std::stoi(members.at(8));
        magic = std::stoi(members.at(9));
    };

    unsigned int get_mana(void);
    unsigned int get_max_mana(void);
    unsigned int get_magic_pts(void);
    // override methods
    unsigned int attack(void) override;
    //void save(std::ofstream& out_file) const override;
    void rest(void) override;
    void show_status(void) const override;
    bool level_up(void) override;
};
#endif
