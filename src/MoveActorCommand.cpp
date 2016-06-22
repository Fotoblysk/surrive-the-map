#include "MoveActorCommand.h"

MoveActorCommand::MoveActorCommand(Actor*& actor_ptr_in, GeneralTools::Direction direction_in):
actor_ptr(actor_ptr_in),
direction(direction_in){
    DEBUG_MSG("Creating MoveActorCommand direction = "<<direction<<std::endl);
}


MoveActorCommand::~MoveActorCommand(){
    DEBUG_MSG("Removing actor move command direction = "<<direction<<std::endl);
}
void MoveActorCommand::execute(){
    //DEBUG_MSG("Exec actor move command"<<std::endl);
    actor_ptr->defaultAccelerationChangeMove(direction);
}


