#ifndef MOVESELECTION_H
#define MOVESELECTIONCOMMAND_H
#include "Command.h"
#include "Menu.h"

class MoveSelectionCommand : public Command
{
    public:
        MoveSelectionCommand(Menu& game_in, Direction direction_in);
        void execute()override;
        virtual ~MoveSelectionCommand();
        int findSelectedOnTextArray();
    protected:

    private:
        Menu& menu;
        Direction direction;
};

#endif // MOVESELECTIONDOWNCOMMAND_H
