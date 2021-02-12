#ifndef FIGHTER_H
#define FIGHTER_H

/**
 * Class inherited from Trainee.
 * 
 * Implement new version of attack with 
 * strike with certiain probability.
 *
 * */

#include "Trainee.h"
#include <random>
#include <time.h>

class Fighter: public Trainee {
private:
    float prob_threshold = 0.8;
public:
    Fighter(Trainee &trainee) : Trainee(trainee){
        class_name = "Fighter";
        type_id = 2;
    };
    Fighter(std::ifstream &file) : Trainee(file){
        class_name = "Fighter";
        type_id = 2;
    };

    // override methods
    unsigned int attack(void) override;
    bool level_up(void) override;
 };

#endif
