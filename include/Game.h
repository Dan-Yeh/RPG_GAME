//TODO desstructor to autosave file
#ifndef GAME_H
#define GAME_H

#include "Characters.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#define DIR_PATH "./saves/"

class Game {
private:
    std::string file_name;
    unsigned int in_game_day = { 0 };

public:
    std::unique_ptr<BaseCharacter> player;

    Game() = default;
    Game(std::string name);
    void save(void);
    void load(void);
    void rest(void);
    void show(void);
    //unique_ptr could not pass to operator<< for now
    //friend std::ostream& operator<<(std::ostream& out, BaseCharacter const & player);
    //friend std::istream& operator>>(std::istream& in, BaseCharacter& player);
};

#endif
