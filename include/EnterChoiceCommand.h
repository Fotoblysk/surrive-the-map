#ifndef ENTERCHOICECOMMAND_H
#define ENTERCHOICECOMMAND_H

#include <Command.h>
#include <Game.h>


class EnterChoiceCommand : public Command
{
    public:
        EnterChoiceCommand(Game& game_in);
        virtual ~EnterChoiceCommand();
        void  execute() override;
        int findSelectedOnTextArray();

    protected:
        Game& game;
    private:
};

#endif // ENTERCHOICECOMMAND_H
