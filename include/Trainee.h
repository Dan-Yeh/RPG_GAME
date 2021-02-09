#ifndef TRAINEE_H
#define TRAINEE_H

#include "Characters.h"
#include <fstream>

class Trainee: public BaseCharacter{
protected:
    unsigned int type_id = 1;
    unsigned int transfer_level = 5;

public:
    Trainee(std::string n = "default", unsigned int hp = 20) : BaseCharacter(n, hp) {}
    Trainee(std::ifstream &file) : BaseCharacter(file) {}


    //abstract method
    virtual void save(std::ofstream &out_file) const;
    virtual void rest(void);
    virtual bool level_up(void);
};

#endif
