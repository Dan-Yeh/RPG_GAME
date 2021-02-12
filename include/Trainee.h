#ifndef TRAINEE_H
#define TRAINEE_H

/**
 * Class inherited from BaseCharacter
 * Class for Trainee and Base class for Mage and Fighter.
 * 
 * Implement basic properties and methods possessed 
 * by all players in game.
 *
 * */

#include "Characters.h"
#include <fstream>

class Trainee : public BaseCharacter {
protected:
    const unsigned int type_id = 1;
    std::string class_name = "Trainee";
    unsigned int transfer_level = 5;

public:
    Trainee(std::string n = "default", unsigned int hp = 20)
        : BaseCharacter(n, hp){}
    Trainee(std::ifstream& file)
        : BaseCharacter(file){}

    //override methods
    std::string get_class_name(void) const override;
    unsigned int get_type_id(void) const override;
    unsigned int get_maxHP(void) const override;
    unsigned int get_HP(void) const override ;
    unsigned int get_attack_pts(void) const override;
    unsigned int get_defense_pts(void) const override;
    unsigned int get_level(void) const override;

    //abstract method
    virtual void save(std::ofstream& out_file) const;
    virtual void rest(void);
    virtual bool level_up(void);
};

#endif
