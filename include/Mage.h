#ifndef MAGE_H
#define MAGE_H

#include "Trainee.h"

class Mage: public Trainee{
private:
    unsigned int mana;
    unsigned int max_mana;
    unsigned int magic;
    
public:
    Mage(std::string n = "default", unsigned int hp = 20);
    Mage(std::ifstream&);
    ~Mage();
    unsigned int get_attack_pts(void) const override;
    void gain_experience(void) override;
    void level_up() override;
    void rest(void) override;
};

#endif
