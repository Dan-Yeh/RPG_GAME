#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class BaseCharacter {
private:
    string name;
    unsigned int max_HP;

public:
    int attack_pts;
    int defense_pts;
    int HP;

    BaseCharacter(string n = "default", int maxhp = 20, int attck_pts = 5, int def_pts = 3, int hp = -1);
    string get_name(void);
    unsigned int get_maxHP(void);
    void show_status(void);
    void rest(void);
    bool isAlive(void);

    friend ostream& operator<<(ostream& out, BaseCharacter& player);
    friend istream& operator>>(istream& in, BaseCharacter& player);
};

#endif
