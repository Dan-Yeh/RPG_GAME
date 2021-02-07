#include "../include/Mage.h"

unsigned int Mage::get_attack_pts(void) const{
    return attack_pts;
}

void Mage::rest(void){
    HP = max_HP;
    std::cout << "Rest to restore HP!" << std::endl;
}

void Mage::gain_experience(void){

}

void Mage::level_up(){

}
