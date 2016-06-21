#ifndef COMMAND_H
#define COMMAND_H
#include"../debugging_tolls.h"
class Command
{
    public:
        virtual ~Command();
        virtual void execute()=0;
    protected:

    private:
};

#endif // COMMAND_H
