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
        MenuInputHandler(GameState& game_state_in, Menu* menu_in, sf::RenderWindow& window_in);//TODO : Don't like that- not readable, use Observer pattern, or just use Game& and make getState() public, and add accessors to menu.
        virtual ~MenuInputHandler();
    private:
        GameState& game_state;
        sf::RenderWindow& window;
        Menu* menu;
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
