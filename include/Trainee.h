#ifndef TRAINEE_H
#define TRAINEE_H

#include "Characters.h"

class Trainee: public BaseCharacter{
private:
    std::string name;
    unsigned int level;
public:
    Trainee(std::string name="default");
    Trainee(std::ifstream&);
    ~Trainee();
    virtual void rest(void);
    virtual void gain_experience(void);
    virtual void level_up(void);
};

#endif
