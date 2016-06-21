#include "CollisionHandler.h"

CollisionHandler::CollisionHandler(Engine & engine_in):
engine(engine_in)
{
    current_command_array = new Command*[SIZE];
}
Command** CollisionHandler::handleInput(){
    for(auto i = 0; i<SIZE; i++)
        current_command_array[i] = nullptr;
    for(auto j = 0; j<engine.bullet.size(); j++)
        for(auto i = 0; i<engine.enemy.size(); i++)
            if(engine.enemy[i]->getGlobalBounds().contains(engine.bullet[j]->getPosition()))
                engine.enemy[i]->is_dead = true;
    return current_command_array;
}
CollisionHandler::~CollisionHandler()
{
    //dtor
}
