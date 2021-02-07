#ifndef MAGE_H
#define MAGE_H

#include "Trainee.h"

class Mage: public Trainee{
private:
    unsigned int mana;
    unsigned int max_mana;
    unsigned int magic;
    
public:
    Mage(std::string n, unsigned int hp) : Trainee(n, hp){};
    Mage(std::ifstream& file) : Trainee(file){};

    // override methods
    void rest(void) override;
    unsigned int get_attack_pts(void) const override;
    
    void gain_experience(void);
    void level_up();
};

#endif
