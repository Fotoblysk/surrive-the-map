#include "MenuInputHandler.h"
#include "EnterChoiceCommand.h"
MenuInputHandler::MenuInputHandler(Game& game_in):
game(game_in),
key_escape(new QuitGameCommand(game)),// memory leaks, object is doubled
closed(key_escape),

key_down(new MoveSelectionCommand(*game.main_menu, Command::Down)),
key_s(key_down),

key_up(new MoveSelectionCommand(*game.main_menu, Command::Up)),
key_w(key_up),

key_space(new EnterChoiceCommand(game))
{
    current_command_array = new Command*[SIZE];
}
MenuInputHandler::~MenuInputHandler()
{
    //dtor
}
Command** MenuInputHandler::handleInput(){
    sf::Event event;
    auto i = 0;
    for(i = 0; i<SIZE; i++)
        current_command_array[i] = nullptr;
    i = 0;
    if (game.getRenderWindow().pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed :
                current_command_array[i++] = closed;
                break;
            case sf::Event::KeyPressed :
                current_command_array[i] = handleKeyInput(event, i);
                break;
            default :
                break;
        }
    }
    return current_command_array;
}
Command* MenuInputHandler::handleKeyInput(sf::Event& event, int& i){
    switch(event.key.code)
    {
        case sf::Keyboard::Escape :
            i++;
            return key_escape;
            break;

        case sf::Keyboard::Down :
            i++;
            return key_down;
            break;
        case sf::Keyboard::S :
            i++;
            return key_s;
            break;

        case sf::Keyboard::Up :
            i++;
            return key_up;
            break;
        case sf::Keyboard::W :
            i++;
            return key_w;
            break;

        case sf::Keyboard::Space :
            i++;
            return key_space;
            break;
        default :
            break;
    }
    return nullptr;
}
