#include "CollisionHandler.h"

CollisionHandler::CollisionHandler(Engine & engine_in):
InputHandler::InputHandler(SIZE),
engine(engine_in)
{
}

Command** CollisionHandler::handleInput(){
    for(auto i = 0; i<SIZE; i++)
        current_command_array[i] = nullptr;;
    for(auto j = 0; j<engine.bullet.size(); j++)
        for(auto i = 0; i<engine.enemy.size(); i++)
            if(engine.enemy[i]->getGlobalBounds().contains(engine.bullet[j]->getPosition()))
                engine.enemy[i]->getShotStatus(false);
    return current_command_array.get();
}
CollisionHandler::~CollisionHandler()
{
    //dtor
}
