#ifndef FIGHTER_H
#define FIGHTER_H

#include "Trainee.h"

class Fighter: public Trainee {
private:

public:
    Fighter(std::string n = "default", unsigned int hp = 20);
    unsigned int get_attack_pts(void) const override;
    void gain_experience(void) override;
    void level_up() override;
};

#endif
