#ifndef STARTSINGLEGAMECOMMAND_H
#define STARTSINGLEGAMECOMMAND_H

#include <Command.h>
#include <Game.h>


class StartSingleGameCommand : public Command
{
    public:
        StartSingleGameCommand(Game& game_in);
        void execute();
        virtual ~StartSingleGameCommand();

    protected:

    private:
        Game& game;
};

#endif // STARTSINGLEGAMECOMMAND_H
