#include "Actor.h"



Actor::~Actor(){
    //dtor
}

bool Actor::getShotStatus()const{
    return shot_status;
}

void Actor::getShotStatus(bool new_shot_status){
    shot_status = new_shot_status;
}
