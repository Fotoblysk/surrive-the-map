#include "GameState.h"

GameState::GameState()
{
    //ctor
}

GameState::~GameState()
{
    //dtor
}
void GameState::changeState(GameState::GameStateStatus new_state){
    game_state_status = new_state;
    DEBUG_MSG("NEW game_state = " << static_cast<int>(game_state_status) << std::endl);
}
GameState::GameStateStatus GameState::getState(){
     return game_state_status;
}
