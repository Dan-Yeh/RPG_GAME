#ifndef MAGE_H
#define MAGE_H

#include "Trainee.h"

class Mage: public Trainee{
private:
    
public:
    Mage(std::string n = "default", unsigned int hp = 20);
    Mage(std::ifstream&);
};

#endif
