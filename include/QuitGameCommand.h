#ifndef QUITGAMECOMMAND_H
#define QUITGAMECOMMAND_H
#include<SFML/Graphics.hpp>
#include "Command.h"
#include "Game.h"
class QuitGameCommand : public Command
{
    public:
        QuitGameCommand(Game& game_in);
        void execute()override;
        virtual ~QuitGameCommand();

    protected:

    private:
        Game& game;
};

#endif // QUITGAMECOMMAND_H
