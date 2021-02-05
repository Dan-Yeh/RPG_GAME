#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <fstream>
#include <iostream>
#include <string>

class BaseCharacter {
private:
    std::string name;
    unsigned int HP;
    unsigned int max_HP;
    unsigned int attack_pts;
    unsigned int defense_pts;


public:
    BaseCharacter(std::string n = "default");
    virtual ~BaseCharacter(){};
    std::string get_name(void) const;
    unsigned int get_maxHP(void) const;
    unsigned int get_HP(void) const;
    unsigned int get_attack_pts(void) const;
    unsigned int get_defense_pts(void) const;
    void sub_HP(unsigned int lose);
    void show_status(void);
    void rest(void);
    bool isAlive(void);
};

#endif
