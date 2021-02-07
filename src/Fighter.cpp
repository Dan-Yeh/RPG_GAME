#include "../include/Fighter.h"

unsigned int Fighter::get_attack_pts(void) const{
    return attack_pts;
}
 
void Fighter::rest(void){
    HP = max_HP;
    std::cout << "Rest to restore HP!" << std::endl;
}
 
void Fighter::gain_experience(void){

}
 
void Fighter::level_up(){

}