#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class BaseCharacter {
private:
    string name;
    int max_HP;

public:
    int attack_pts;
    int defense_pts;
    int HP;
    int in_game_day;

    BaseCharacter(string n="default", int maxhp = 20, int attck_pts = 5, int def_pts = 3, int hp = -1, int ingame_day = 0);
    string get_name(void);
    void show_status(void);
    void rest(void);
    bool isAlive(void);


    friend ostream& operator <<(ostream& out, BaseCharacter& player);
    friend istream& operator >>(istream& in, BaseCharacter& player);
};

#endif
