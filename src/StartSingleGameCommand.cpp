#include "StartSingleGameCommand.h"

StartSingleGameCommand::StartSingleGameCommand(Game& game_in):
game(game_in)
{

}
StartSingleGameCommand::~StartSingleGameCommand()
{
    //dtor
}
void StartSingleGameCommand::execute(){
    game.startSinglePlayer();
}
