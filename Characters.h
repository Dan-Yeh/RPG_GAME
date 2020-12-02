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
    unsigned int in_game_day = { 0 };

public:
    BaseCharacter(std::string n = "default", unsigned int hp = 20);
    BaseCharacter(std::ifstream&);
    std::string get_name(void);
    unsigned int get_maxHP(void);
    unsigned int get_HP(void);
    unsigned int get_attack_pts(void);
    unsigned int get_defense_pts(void);
    unsigned int get_in_game_day(void);
    void sub_HP(unsigned int lose);
    void show_status(void);
    void rest(void);
    bool isAlive(void);
};

#endif
