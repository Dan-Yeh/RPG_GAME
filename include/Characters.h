#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <fstream>
#include <iostream>
#include <string>

class BaseCharacter {
protected:
    std::string name;
    unsigned int type_id;
    unsigned int HP = 20;
    unsigned int max_HP = 20;
    unsigned int attack_pts = 5;
    unsigned int defense_pts = 3;
    unsigned int level = 1;


public:
    BaseCharacter(std::string n = "default", unsigned int hp = 20);
    BaseCharacter(std::ifstream &file);
    
    std::string get_name(void) const;
    unsigned int get_type_id(void) const;
    unsigned int get_maxHP(void) const;
    unsigned int get_HP(void) const;
    unsigned int get_attack_pts(void) const;
    unsigned int get_defense_pts(void) const;
    unsigned int get_level(void) const;
    unsigned sub_HP(unsigned int attack_pts, unsigned int defense_pts);
    unsigned int defend(void);
    bool isAlive(void);

    // abstract methods
    virtual ~BaseCharacter() {};
    virtual unsigned int attack(void);
    virtual void show_status(void) const;
};

#endif
