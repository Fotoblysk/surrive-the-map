#include "InputHandler.h"
InputHandler::InputHandler(int size) :
current_command_array(new Command*[size])
{
}

InputHandler::~InputHandler()
{
    //dtor
}
