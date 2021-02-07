#ifndef FIGHTER_H
#define FIGHTER_H

#include "Trainee.h"

class Fighter: public Trainee {
public:
    Fighter(std::string n, unsigned int hp) : Trainee(n, hp){};
    Fighter(std::ifstream& file) : Trainee(file){};

    // override methods
    void rest(void) override;
    unsigned int get_attack_pts(void) const override;
    
    void gain_experience(void);
    void level_up();
};

#endif
