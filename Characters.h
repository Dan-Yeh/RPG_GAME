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

    BaseCharacter();
    BaseCharacter(string n, unsigned int maxhp = 20, int attck_pts = 5, int def_pts = 3, int hp = -1)
    {
        name = n;
        max_HP = maxhp;
        if (hp >= 0)
            HP = hp;
        else
            HP = max_HP;
        attack_pts = attck_pts;
        defense_pts = def_pts;
    }

    BaseCharacter(ifstream file)
    {
    }

    string get_name(void)
    {
        return name;
    }

    unsigned int get_maxHP(void)
    {
        return max_HP;
    }

    void show_status(void)
    {
        cout << "Name: " << name << endl;
        cout << "Current HP is " << HP << endl;
        cout << "Attack points: " << attack_pts << endl;
        cout << "Defense points: " << defense_pts << endl;
    }

    void rest(void)
    {
        HP = max_HP;
        cout << "Rest to restore HP!" << endl;
    }

    bool isAlive(void)
    {
        return (HP > 0);
    }
};

#endif
