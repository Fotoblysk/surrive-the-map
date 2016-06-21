#ifndef MOVESELECTION_H
#define MOVESELECTIONCOMMAND_H
#include "Command.h"
#include "Menu.h"
#include "../GeneralTools.h"

class MoveSelectionCommand : public Command
{
    public:
        MoveSelectionCommand(Menu& game_in, GeneralTools::Direction direction_in);
        void execute()override;
        virtual ~MoveSelectionCommand();
        int findSelectedOnTextArray();
    protected:

    private:
        Menu& menu;
        GeneralTools::Direction direction;
};

#endif // MOVESELECTIONDOWNCOMMAND_H
