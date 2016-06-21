#include "Game.h"
#include "MenuInputHandler.h"
#include "MainMenu.h"
#include "EngineInputHandler.h"
Game::Game(sf::RenderWindow& window_in):
    window(window_in),
    state(MenuState),
    main_menu(nullptr),
    engine(nullptr)
{
    menu_input = nullptr;
}
Game::~Game()
{
}
void Game::changeState(GameState new_state){
    state = new_state;
}
sf::RenderWindow& Game::getRenderWindow(){
    return window;
}
void Game::menu(){
    main_menu = std::move(std::unique_ptr <Menu> (new MainMenu));
    menu_input = std::move(std::unique_ptr <InputHandler> (new MenuInputHandler(*this)));
    window.clear();
    while (state == MenuState)
    {
        main_menu->render(window);
        Command** current_command(menu_input->handleInput());
        for(auto i = 0; current_command[i] != nullptr  &&  i < SIZE; i++)
            current_command[i]->execute();
        window.display();
        window.clear();
    }
}
void Game::run(){
    state = MenuState;
    stateMachine();
}
void Game::startSinglePlayer(){
    window.clear();
    DEBUG_MSG("YOU RUNNED SINGLEPLAYER GAME \n AWSOME :D"<<std::endl);
    engine = std::move(std::unique_ptr <Engine>(new Engine(window)));
    menu_input = std::move(std::unique_ptr<InputHandler>(new EngineInputHandler(*this)));
    //const int TIME_STEP_AS_MICROS = 33333;
    long long accumulator = 0;
    sf::Clock clock;
    while(state == PlaySingleState)
    {
        accumulator += clock.restart().asMicroseconds();
        if( accumulator > TIME_STEP_AS_MICROS )
        {
            sf::Time elapsed1 = clock.getElapsedTime();
            Command** current_command(menu_input->handleInput());
            for(auto i = 0; current_command[i] != nullptr  &&  i < SIZE; i++)
                current_command[i]->execute();
            engine->update();
            engine->render();
            window.display();
            window.clear();
            accumulator -= TIME_STEP_AS_MICROS;
        }
        if(accumulator > 2*TIME_STEP_AS_MICROS)
            DEBUG_MSG("Slow refresh: "<<accumulator <<std::endl);
    }
    state = MenuState;
}
void Game::stateMachine(){
    while(state != EndState)
    {
        switch(state)
        {
        case MenuState :
            menu();
            break;
        case PlaySingleState :
            startSinglePlayer();
            break;
        }
    }
}

