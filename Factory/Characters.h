#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <fstream>
#include <iostream>
#include <string>

/**
 * In namespace CharacterFactory
 * Base Class for Trainee and Villain.
 * 
 * Implement basic properties and methods possessed 
 * by all characters in game.
 * */

namespace CharacterFactory {
class BaseCharacter {
protected:
    std::string name;
    std::string class_name;
    unsigned int type_id;
    unsigned int HP = 20;
    unsigned int max_HP = 20;
    unsigned int attack_pts = 5;
    unsigned int defense_pts = 3;
    //TODO:4 for test, remember change to 1 after fix bug
    unsigned int level = 3;

public:
    BaseCharacter(std::string n = "default", unsigned int hp = 20);
    BaseCharacter(std::ifstream& file);

    std::string get_name(void) const;
    std::string get_class_name(void) const;
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
}
#endif
