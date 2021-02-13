#ifndef FIGHTER_H
#define FIGHTER_H

#include "Trainee.h"
#include "../Utilities/utils.h"
#include <random>
#include <string>
#include <time.h>
#include <vector>
#include <cstdlib>

/**
 * Class inherited from Trainee.
 * 
 * Implement new version of attack with 
 * strike with certiain probability.
 *
 * */

class Fighter : public Trainee {
private:
    float prob_threshold = 0.8;

public:
    Fighter(Trainee& trainee)
        : Trainee(trainee)
    {
        class_name = "Fighter";
        type_id = 2;
    };
    Fighter(std::vector<std::string> &members)
        : Trainee(members)
    {
        class_name = "Fighter";
    };

    // override methods
    unsigned int attack(void) override;
    bool level_up(void) override;
};
#endif
