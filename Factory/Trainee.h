#ifndef TRAINEE_H
#define TRAINEE_H

#include "Characters.h"
#include <fstream>

/**
 * Class inherited from BaseCharacter
 * Class for Trainee and Base class for Mage and Fighter.
 * 
 * Implement basic properties and methods possessed 
 * by all players in game.
 *
 * */
class Trainee : public CharacterFactory::BaseCharacter {
protected:
    unsigned int transfer_level = 5;

public:
    Trainee(std::string n = "default", unsigned int hp = 20)
        : BaseCharacter(n, hp)
    {
        class_name = "Trainee";
        type_id = 1;
    }
    Trainee(std::vector<std::string> &members)
        : BaseCharacter(members)
    {
        class_name = "Trainee";
        std::cout << "Trainee Constructor\n";
    }

    //override methods

    //abstract method
    virtual void rest(void);
    virtual bool level_up(void);
};
#endif
