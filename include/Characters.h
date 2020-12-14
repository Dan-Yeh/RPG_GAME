#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <fstream>
#include <iostream>
#include <string>

class BaseCharacter {
private:
    std::string name;
    unsigned int HP = { 20 };
    unsigned int max_HP = { 20 };
    unsigned int attack_pts = { 5 };
    unsigned int defense_pts = { 3 };

public:
    BaseCharacter(std::string n = "default", unsigned int hp = 20);
    BaseCharacter(std::ifstream&);
    const std::string get_name(void);
    const unsigned int get_maxHP(void);
    const unsigned int get_HP(void);
    const unsigned int get_attack_pts(void);
    const unsigned int get_defense_pts(void);
    void sub_HP(unsigned int lose);
    void show_status(void);
    void rest(void);
    bool isAlive(void);
};

#endif
