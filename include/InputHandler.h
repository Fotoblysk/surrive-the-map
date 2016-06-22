#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include"Command.h"
#include<memory>
#define SIZE 10
class InputHandler
{
    public:
        InputHandler(int size);
        virtual ~InputHandler();
        virtual Command** handleInput()=0;
    protected:
        std::unique_ptr<Command*[]> current_command_array;
};

#endif // INPUTHANDLER_H
