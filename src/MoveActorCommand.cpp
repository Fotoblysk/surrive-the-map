#include "MoveActorCommand.h"

MoveActorCommand::MoveActorCommand(Actor*& actor_ptr_in, Direction direction_in):
actor_ptr(actor_ptr_in),
direction(direction_in){

}


MoveActorCommand::~MoveActorCommand(){

}
void MoveActorCommand::execute(){
    switch(direction)
    {
    case Right:
        actor_ptr->accelerationRight();
        break;
    case Left:
        actor_ptr->accelerationLeft();
        break;
    case Up:
        actor_ptr->accelerationUp();
        break;
    case Down:
        actor_ptr->accelerationDown();
        break;
    }
}


