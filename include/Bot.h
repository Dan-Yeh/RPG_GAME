#ifndef BOT_H
#define BOT_H

#include "Engine.h"

class Bot {
private:
    Engine engine;
    std::string mode;
    void menu();
    void mage_demo();
    void fighter_demo();

public:
    Bot();
    void demo();
};

#endif