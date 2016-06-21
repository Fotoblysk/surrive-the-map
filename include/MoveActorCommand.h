#ifndef MOVERIGHTCOMMAND_H
#define MOVERIGHTCOMMAND_H

#include <Command.h>
#include <Game.h>


class MoveActorCommand : public Command
{
    public:
        MoveActorCommand(Actor*& actor_ptr_in, Direction direction_in);
        void execute()override;
        virtual ~MoveActorCommand();
        int findSelectedOnTextArray();
    protected:

    private:
        Actor*& actor_ptr;
        Direction direction;
};

#endif // MOVERIGHTCOMMAND_H
