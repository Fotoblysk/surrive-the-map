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
        virtual ~MenuInputHandler();
    private:
        Game& game;
        Command* handleKeyInput(sf::Event& event, int& i);


        Command* key_escape;//sf::Event::key::code::Escape
        Command* closed;

        Command* key_down;
        Command* key_s;

        Command* key_up;
        Command* key_w;

        Command* key_space;


};

#endif // MENUINPUTHANDLER_H
