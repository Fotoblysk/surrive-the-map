#ifndef ENTERCHOICECOMMAND_H
#define ENTERCHOICECOMMAND_H

#include <Command.h>
#include <Game.h>


class EnterChoiceCommand : public Command
{
    public:
        EnterChoiceCommand(GameState& game_state_in, Menu* menu_in);
        virtual ~EnterChoiceCommand();
        void  execute() override;
        int findSelectedOnTextArray();

    protected:
        GameState& game_state;
        Menu* menu;
    private:
};

#endif // ENTERCHOICECOMMAND_H
