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

        Command* key_escape;//sf::Event::key::code::Escape
        Command* closed;

        Command* key_d;
        Command* key_right;

        Command* key_s;
        Command* key_down;

        Command* key_w;
        Command* key_up;

        Command* key_a;
        Command* key_left;

        Command* key_q;
        Command* l_mouse_button;

};

#endif // ENGINEINPUTHANDLER_H
