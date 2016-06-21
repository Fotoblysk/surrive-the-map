#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include"Command.h"
#include<memory>
#define SIZE 10
class InputHandler
{
    public:
        virtual ~InputHandler();
        virtual Command** handleInput()=0;
    protected:
        Command** current_command_array;
};

#endif // INPUTHANDLER_H
