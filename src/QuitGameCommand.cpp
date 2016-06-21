#include "QuitGameCommand.h"

QuitGameCommand::QuitGameCommand(Game& game_in):
game(game_in)
{

}


QuitGameCommand::~QuitGameCommand()
{

}
void QuitGameCommand::execute(){
   // game.getRenderWindow().close();
    game.changeState(Game::EndState);
}
