#ifndef ENGINEINPUTHANDLER_H
#define ENGINEINPUTHANDLER_H
#include "Command.h"
#include "InputHandler.h"
#include "Game.h"

class EngineInputHandler : public InputHandler
{
    public:
        Command** handleInput()override;
        EngineInputHandler(Game& game_in);
        virtual ~EngineInputHandler();
    private:
        Game& game;
        Command* handleKeyInput(sf::Event& event, int& i);
        Command** handleRealTimeKeyInput(sf::Event& event, int& i);

        std::shared_ptr<Command> key_escape;//sf::Event::key::code::Escape
        std::shared_ptr<Command> closed;

        std::shared_ptr<Command> key_d;
        std::shared_ptr<Command> key_right;

        std::shared_ptr<Command> key_s;
        std::shared_ptr<Command> key_down;

        std::shared_ptr<Command> key_w;
        std::shared_ptr<Command> key_up;

        std::shared_ptr<Command> key_a;
        std::shared_ptr<Command> key_left;

        std::shared_ptr<Command> key_q;
        std::shared_ptr<Command> l_mouse_button;

};

#endif // ENGINEINPUTHANDLER_H
