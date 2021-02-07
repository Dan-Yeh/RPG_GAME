#ifndef TRAINEE_H
#define TRAINEE_H

#include "Characters.h"

class Trainee: public BaseCharacter{
protected:
    unsigned int level;
public:
    Trainee(std::string n = "default", unsigned int hp = 20) : BaseCharacter(n, hp) {}
    Trainee(std::ifstream& file) : BaseCharacter(file) {}

    // override methods
    unsigned int get_attack_pts(void) const override;
    void rest(void) override;
    
    void gain_experience(void);
    void level_up(void);
};

#endif
