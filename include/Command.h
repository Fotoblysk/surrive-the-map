#ifndef COMMAND_H
#define COMMAND_H
class Command
{
    public:
    enum Direction {Left, Right, Up, Down};
        virtual ~Command();
        virtual void execute()=0; //TODO: EASY write it all with new MainMenu class

    protected:

    private:
};

#endif // COMMAND_H
