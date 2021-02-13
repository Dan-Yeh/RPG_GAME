#include "../include/Bot.h"

Bot::Bot() {
    menu();
}

void Bot::menu()
{
    /*Initailize*/
    std::cout << "******************************************\n";
    std::cout << "*         Welcome to Demo Mode!!!        *\n";
    std::cout << "*  For demo of being a Mage, enter m.    *\n";
    std::cout << "*  For demo of being a Fighter, enter f. *\n";
    std::cout << "*  If you want to Exit demo, enter q.    *\n";
    std::cout << "******************************************\n";
}

void Bot::demo() {
    while(true) {
        std::cin >> mode;
        if(mode == "m") {
            mage_demo();
            break;
        } else if(mode == "f") {
            fighter_demo();
            break;
        } else if(mode == "q") {
            break;
        } else {
            std::cout << "Invalid Input! Please Try again!\n";
        }
    }
    
}

void Bot::mage_demo() {

}

void Bot::fighter_demo() {
    
}