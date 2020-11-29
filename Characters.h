#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <iostream>
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

    BaseCharacter(string n, int maxhp = 20, int attck_pts = 5, int def_pts = 3, int hp = -1, int ingame_day = 0)
    {
        name = n;
        max_HP = maxhp;
        if (hp >= 0)
            HP = hp;
        else
            HP = max_HP;
        attack_pts = attck_pts;
        defense_pts = def_pts;
        in_game_day = ingame_day;
    }

    string get_name(void){
        return name;
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
        in_game_day++;
        cout << "Rest to restore HP!" << endl;
    }

    bool isAlive(void)
    {
        return (HP > 0);
    }
};

#endif
