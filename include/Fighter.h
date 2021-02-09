#ifndef FIGHTER_H
#define FIGHTER_H

#include "Trainee.h"
#include <random>
#include <time.h>

class Fighter: public Trainee {
private:
    unsigned int type_id = 3;
    unsigned int level = 5;
    unsigned int HP = 40;
    float prob_threshold = 0.8;
public:
    Fighter(std::string n, unsigned int hp) : Trainee(n, hp){};
    Fighter(std::ifstream &file) : Trainee(file){};

    // override methods
    unsigned int attack(void) override;
    bool level_up(void) override;
 };

#endif
