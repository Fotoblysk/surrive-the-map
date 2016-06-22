#ifndef QUITGAMECOMMAND_H
#define QUITGAMECOMMAND_H
#include<SFML/Graphics.hpp>
#include "Command.h"
#include "Game.h"
class QuitGameCommand : public Command
{
    public:
        QuitGameCommand(GameState& game_state_in);
        void execute()override;
        virtual ~QuitGameCommand();

    protected:

    private:
        GameState& game_state;
};

#endif // QUITGAMECOMMAND_H
