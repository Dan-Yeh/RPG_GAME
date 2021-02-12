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
    const unsigned int type_id = 2;
    std::string class_name = "Fighter";
    unsigned int level = 5;
    unsigned int HP = 40;
    float prob_threshold = 0.8;
public:
    Fighter(std::string n, unsigned int hp) : Trainee(n, hp){};
    Fighter(std::ifstream &file) : Trainee(file){};

    // override methods
    std::string get_class_name(void) const override;
    unsigned int get_type_id(void) const override;
    unsigned int get_maxHP(void) const override;
    unsigned int get_HP(void) const override ;
    unsigned int get_attack_pts(void) const override;
    unsigned int get_defense_pts(void) const override;
    unsigned int get_level(void) const override;
    unsigned int attack(void) override;
    bool level_up(void) override;
 };

#endif
