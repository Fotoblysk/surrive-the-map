#ifndef MOVERIGHTCOMMAND_H
#define MOVERIGHTCOMMAND_H
#include "../GeneralTools.h"
#include <Command.h>
#include <Game.h>


class MoveActorCommand : public Command
{
    public:
        MoveActorCommand(Actor*& actor_ptr_in, GeneralTools::Direction direction_in);
        void execute()override;
        virtual ~MoveActorCommand();
        int findSelectedOnTextArray();
    protected:

    private:
        Actor*& actor_ptr;
        GeneralTools::Direction direction;
};

#endif // MOVERIGHTCOMMAND_H
