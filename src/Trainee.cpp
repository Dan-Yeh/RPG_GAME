#include "../include/Trainee.h"

unsigned int Trainee::get_attack_pts(void) const{
    return attack_pts;
}

void Trainee::rest(void){
    HP = max_HP;
    std::cout << "Rest to restore HP!" << std::endl;
}

void Trainee::gain_experience(void){

}

void Trainee::level_up(void){

}

