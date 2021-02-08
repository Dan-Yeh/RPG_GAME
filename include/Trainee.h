#ifndef TRAINEE_H
#define TRAINEE_H

#include "Characters.h"

class Trainee: public BaseCharacter{
protected:
    unsigned int transfer_level = 5;
public:
    Trainee(std::string n = "default", unsigned int hp = 20) : BaseCharacter(n, hp) {}
    Trainee(std::ifstream& file) : BaseCharacter(file) {}

    // override methods

    //abstract method
    virtual void rest(void);
    virtual bool level_up(void);
};

#endif
