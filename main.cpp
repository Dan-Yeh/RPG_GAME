#include <iostream>
#include <string>

int main()
{
    int HP = 10;
    char init_status;
    std::string action;

    /*Initailize*/
    std::cout << "***********************************\n";
    std::cout << "*      Welcome to RPG game!!!     *\n";
    std::cout << "*  For playing New Game, enter n. *\n";
    std::cout << "*  For playing Old Game, enter o. *\n";
    std::cout << "*  If you want to Exit, enter q.  *\n";
    std::cout << "***********************************\n";

    std::cin >> init_status;

    while (true) {
        if (init_status == 'o') {
            //load
            break;
        } else if (init_status == 'n') {
            //new record
            break;
        } else if (init_status == 'q') {
            HP = -1; // would skip game logic
            break;
        } else
            std::cout << "Invalid Input! Please Try again!\n";
    }

    std::cout << "****************************************\n";
    std::cout << "*            Game Instructions         *\n";
    std::cout << "*          To fight, enter fight.      *\n";
    std::cout << "*  To show current status, enter show. *\n";
    std::cout << "*  To save current status, enter save. *\n";
    std::cout << "*      If you want to Exit, enter q.   *\n";
    std::cout << "****************************************\n";

    /*Playing game*/
    while (HP > 0) {
        std::cin >> action;
        if (action == "fight") {
            HP -= 2;
            std::cout << "You've been attacked, losed 2 HP!\n";
            continue;
        } else if (action == "show") {
            std::cout << "Your HP is " << HP << ".\n";
            continue;
        } else if (action == "save") {
            //save
            std::cout << "Successfully Saved!\n";
            continue;
        } else if (action == "q") {
            //autosave
            break;
        } else {
            std::cout << "Invalid Input! Please Try again!\n";
        }
    }

    if (HP == 0) {
        std::cout << "You died!\n";
        //save ????
    }

    return 0;
}
