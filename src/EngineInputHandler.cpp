#include "EngineInputHandler.h"
#include "QuitGameCommand.h"
#include "MoveActorCommand.h"
#include "SpawnBulletCommand.h"
#include <SFML/System/Vector2.hpp>

EngineInputHandler::EngineInputHandler(Game& game_in):
game(game_in),
key_escape(new QuitGameCommand(game)),// memory leaks, object is doubled
closed(key_escape),

key_d(new MoveActorCommand(game.engine->current_player, GeneralTools::Right)),
key_right(key_d),

key_s(new MoveActorCommand(game.engine->current_player, GeneralTools::Down)),
key_down(key_s),

key_w(new MoveActorCommand(game.engine->current_player, GeneralTools::Up)),
key_up(key_w),

key_a(new MoveActorCommand(game.engine->current_player, GeneralTools::Left)),
key_left(key_a),

key_q(new SpawnBulletCommand(game, sf::Vector2f(float (0.1), float (0.1)))),
l_mouse_button(key_q)
{
    current_command_array = new Command*[SIZE];
}
EngineInputHandler::~EngineInputHandler()
{
    //dtor
}
Command** EngineInputHandler::handleInput(){
    sf::Event event;
    auto i = 0;
    for(i = 0; i<SIZE; i++)
        current_command_array[i]=  nullptr;
    i=0;
    while (game.getRenderWindow().pollEvent(event))
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
    return handleRealTimeKeyInput(event, i);
}
Command* EngineInputHandler::handleKeyInput(sf::Event& event, int& i){
    switch(event.key.code)
    {
        case sf::Keyboard::Escape :
            i++;
            return key_escape;
            break;
        default :
            break;
    }
    return nullptr;
}
Command** EngineInputHandler::handleRealTimeKeyInput(sf::Event& event, int& i){ //TODO: works only with one key at the same time

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        current_command_array[i++] = key_d;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        current_command_array[i++] = key_a;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        current_command_array[i++] = key_w;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        current_command_array[i++] = key_s;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        current_command_array[i++] = key_q;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        current_command_array[i++] = key_q;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        current_command_array[i++] = key_right;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        current_command_array[i++] = key_left;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        current_command_array[i++] = key_up;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) //TODO: to fix
        current_command_array[i++] = key_down;
    return current_command_array;
}

