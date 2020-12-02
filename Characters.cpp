#include "Characters.h"

using namespace std;

BaseCharacter::BaseCharacter(string n, int maxhp, int attck_pts, int def_pts, int hp)
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

string BaseCharacter::get_name(void){
    return name;
}

void BaseCharacter::show_status(void)
{
    cout << "Name: " << name << endl;
    cout << "Current HP is " << HP << endl;
    cout << "Attack points: " << attack_pts << endl;
    cout << "Defense points: " << defense_pts << endl;
}

void BaseCharacter::rest(void)
{
    HP = max_HP;
    cout << "Rest to restore HP!" << endl;
}

bool BaseCharacter::isAlive(void)
{
    return (HP > 0);
}

ostream& operator <<(ostream& out, BaseCharacter &player)
{ 
    out << player.name << endl
        << player.max_HP << endl
        << player.attack_pts << endl
        << player.defense_pts << endl
        << player.HP << endl;
    return out;
}

istream& operator >>(istream& in, BaseCharacter &player)
{
    in  >> player.name 
        >> player.max_HP
        >> player.attack_pts
        >> player.defense_pts
        >> player.HP;
    return in;
}
