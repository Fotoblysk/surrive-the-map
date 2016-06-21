#ifndef MENUCOMMAND_H
#define MENUCOMMAND_H
#include"Command.h"
#include"SFML/Graphics.hpp"


class MenuCommand : public Command
{
    public:
        virtual void execute() = 0;
        virtual ~MenuCommand();

    protected:
  //      sf::RenderWindow& widnow;

    private:
};

#endif // MENUCOMMAND_H
