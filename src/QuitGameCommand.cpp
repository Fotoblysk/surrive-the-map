#include "QuitGameCommand.h"

QuitGameCommand::QuitGameCommand(GameState& game_state_in):
game_state(game_state_in)
{

}


QuitGameCommand::~QuitGameCommand()
{

}
void QuitGameCommand::execute(){
   // game.getRenderWindow().close();
    game_state.changeState(GameState::EndState);
}
