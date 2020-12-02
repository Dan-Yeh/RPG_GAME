#ifndef GAME_H
#define GAME_H

#include "Characters.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#define DIR_PATH "./saves/"

using namespace std;

class Game {
public:
    Game()
    {
        in_game_day = 0;
    }
    void save(string file_name, unique_ptr<BaseCharacter> ptr)
    {
        ofstream file;
        file.open(DIR_PATH + file_name + ".txt", ofstream::trunc); //trunc for overwrite
        if (file.is_open()) {
            file << ptr->get_name() << ";" << ptr->HP << ";" << ptr->get_maxHP() << ";"
                 << ptr->attack_pts << ";" << ptr->defense_pts << ";"
                 << "\n";
            file.close();
        } else {
            cout << "Cannot open the File.\n";
        }
    }
    unique_ptr<BaseCharacter> load(string file_name)
    {
        unique_ptr<BaseCharacter> player;
        ifstream file(DIR_PATH + file_name + ".txt");
        if (file.peek() == ifstream::traits_type::eof()) {
            cout << "The record is empty! Please start a new game.\n";
        } else {
            player = make_unique<BaseCharacter>(BaseCharacter(file));
            //TODO using file as constructor's argument
        }
        return player;
    }



private:
    unsigned int in_game_day;
};

#endif
