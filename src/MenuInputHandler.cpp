#include "MenuInputHandler.h"
#include "EnterChoiceCommand.h"
MenuInputHandler::MenuInputHandler(GameState& game_state_in, Menu* menu_in, sf::RenderWindow& window_in):
window(window_in),
InputHandler::InputHandler(SIZE),
game_state(game_state_in),
menu(menu_in),
key_escape(new QuitGameCommand(game_state_in)),


key_down(new MoveSelectionCommand(menu_in, GeneralTools::Down)),

key_up(new MoveSelectionCommand(menu_in, GeneralTools::Up)),

key_space(new EnterChoiceCommand(game_state_in, menu_in))
{
    closed = key_escape;
    key_s = key_down;
    key_w = key_up;
}
MenuInputHandler::~MenuInputHandler(){
    DEBUG_MSG("MenuInputHandler delete"<<std::endl);
}
Command** MenuInputHandler::handleInput(){
    sf::Event event;
    auto i = 0;
    for(i = 0; i<SIZE; i++)
        current_command_array[i] = nullptr;
    i = 0;
    if (window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed :
                current_command_array[i++] = closed.get();
                break;
            case sf::Event::KeyPressed :
                current_command_array[i] = handleKeyInput(event, i);
                break;
            default :
                break;
        }
    }
    return current_command_array.get();
}
Command* MenuInputHandler::handleKeyInput(sf::Event& event, int& i){
    switch(event.key.code)
    {
        case sf::Keyboard::Escape :
            i++;
            return key_escape.get();
            break;

        case sf::Keyboard::Down :
            i++;
            return key_down.get();
            break;
        case sf::Keyboard::S :
            i++;
            return key_s.get();
            break;

        case sf::Keyboard::Up :
            i++;
            return key_up.get();
            break;
        case sf::Keyboard::W :
            i++;
            DEBUG_MSG("w detected"<<std::endl);
            return key_w.get();
            break;

        case sf::Keyboard::Space :
            i++;
            return key_space.get();
            break;
        default :
            break;
    }
    return nullptr;
}
