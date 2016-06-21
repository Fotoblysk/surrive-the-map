#ifndef MENUINPUTHANDLER_H
#define MENUINPUTHANDLER_H
#include"InputHandler.h"
#include"QuitGameCommand.h"
#include"MoveSelectionCommand.h"
#include"Game.h"
#include"SFML/Graphics.hpp"
class MenuInputHandler: public InputHandler
{
    public:
        Command** handleInput()override;
        MenuInputHandler(Game& game_in);
        virtual ~MenuInputHandler(){DEBUG_MSG("destroy  ");}
    private:
        Game& game;
        Command* handleKeyInput(sf::Event& event, int& i);


        std::shared_ptr<Command> key_escape;//sf::Event::key::code::Escape
        std::shared_ptr<Command> closed;

        std::shared_ptr<Command> key_down;
        std::shared_ptr<Command> key_s;

        std::shared_ptr<Command> key_up;
        std::shared_ptr<Command> key_w;

        std::shared_ptr<Command> key_space;


};

#endif // MENUINPUTHANDLER_H
