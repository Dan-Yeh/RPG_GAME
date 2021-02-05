#ifndef TRAINEE_H
#define TRAINEE_H

#include "Characters.h"

class Trainee: public BaseCharacter{
private:
    std::string name;

public:
    Trainee(std::string n = "default", unsigned int hp = 20);
    Trainee(std::ifstream&);
    void rest(void);
};

#endif
