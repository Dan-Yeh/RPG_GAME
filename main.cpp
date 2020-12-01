#include "Characters.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    char init_status;
    string action;
    unique_ptr<BaseCharacter> player; 

    /*Initailize*/
    cout << "***********************************\n";
    cout << "*      Welcome to RPG game!!!     *\n";
    cout << "*  For playing New Game, enter n. *\n";
    cout << "*  For playing Old Game, enter o. *\n";
    cout << "*  If you want to Exit, enter q.  *\n";
    cout << "***********************************\n";


    while (true) {
        cin >> init_status;
        if (init_status == 'o') {
            BaseCharacter dummy;
            ifstream in("log.txt");
            in >> dummy;
            player = make_unique<BaseCharacter>(dummy);
            break;
        } else if (init_status == 'n') {
            string character_name;
            cout << "Please input a character name: " << endl;
            cin >> character_name;
            player = make_unique<BaseCharacter>(character_name);
            break;
        } else if (init_status == 'q') {
            goto End; // would skip game logic
        } else
            cout << "Invalid Input! Please Try again!\n";
    }

    cout << "****************************************\n";
    cout << "*            Game Instructions         *\n";
    cout << "*          To fight, enter fight.      *\n";
    cout << "*  To show current status, enter show. *\n";
    cout << "*  To save current status, enter save. *\n";
    cout << "*      If you want to Exit, enter q.   *\n";
    cout << "****************************************\n";

    /*Playing game*/
    while (player->HP > 0) {
        cin >> action;
        if (action == "fight") {
            cout << "A Gobelin appears\n";
            unique_ptr<BaseCharacter> enemy = make_unique<BaseCharacter>("Gobelin", 15);
            while (true) {
                //TODO : add playing logic
                if (!enemy->isAlive()){
                    string n = enemy->get_name();
                    cout << "The " << n << " is dead! You win!\n";
                    break;
                }
                if (!player->isAlive()){
                    cout << "You're defeated!\n";
                    break;
                }
            }
            continue;
        } else if (action == "rest"){
            player->rest();
            continue;
        } else if (action == "show") {
            player->show_status();
            continue;
        } else if (action == "save") {
            ofstream out("log.txt");
            out << *player;
            cout << "Successfully Saved!\n";
            continue;
        } else if (action == "q") {
            break;
        } else {
            cout << "Invalid Input! Please Try again!\n";
        }
    }

    if (player->HP == 0) {
        cout << "You died!\n";
    }

End:
    return 0;
}
