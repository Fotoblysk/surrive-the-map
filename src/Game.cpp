#include "Game.h"
#include "MenuInputHandler.h"
#include "MainMenu.h"
#include "EngineInputHandler.h"
Game::Game(sf::RenderWindow& window_in):
    window(window_in),
    main_menu(nullptr),
    engine(nullptr),
    input(nullptr)
{
    game_state.changeState(GameState::MenuState);
}
Game::~Game()
{
    DEBUG_MSG("Game delete"<<std::endl);
}

sf::RenderWindow& Game::getRenderWindow(){
    return window;
}
void Game::menu(){
    main_menu = std::move(std::unique_ptr <Menu> (new MainMenu));
    input = std::move(std::unique_ptr <InputHandler> (new MenuInputHandler(game_state, main_menu.get(), window)));
    window.clear();
    while (game_state.getState() == GameState::MenuState)
    {
        main_menu->render(window);
        Command** current_command(input->handleInput());
        for(auto i = 0; current_command[i] != nullptr  &&  i < SIZE; i++)
            current_command[i]->execute();
        window.display();
        window.clear();
    }
}
void Game::run(){
    game_state.changeState(GameState::MenuState);
    stateMachine();
}
void Game::startSinglePlayer(){
    window.clear();
    DEBUG_MSG("YOU RUNNED SINGLEPLAYER GAME \n AWSOME :D"<<std::endl);
    engine = std::move(std::unique_ptr <Engine>(new Engine(window)));
    input = std::move(std::unique_ptr<InputHandler>(new EngineInputHandler(*this)));
    //const int TIME_STEP_AS_MICROS = 33333;
    long long accumulator = 0;
    sf::Clock clock;
    while(game_state.getState() == GameState::PlaySingleState)
    {
        accumulator += clock.restart().asMicroseconds();
        if( accumulator > TIME_STEP_AS_MICROS )
        {
            sf::Time elapsed1 = clock.getElapsedTime();
            Command** current_command(input->handleInput());
            for(auto i = 0; current_command[i] != nullptr  &&  i < SIZE; i++)
                current_command[i]->execute();
            engine->update();
            engine->render();
            window.display();
            window.clear();
            accumulator -= TIME_STEP_AS_MICROS;
        }
        if(accumulator > 2*TIME_STEP_AS_MICROS)
            DEBUG_MSG("Slow refresh: "<<accumulator <<"us"<<std::endl);
    }
    game_state.changeState(GameState::MenuState);
}
void Game::stateMachine(){
    while(game_state.getState() != GameState::EndState)
    {
        switch(game_state.getState())
        {
        case GameState::MenuState :
            menu();
            break;
        case GameState::PlaySingleState :
            startSinglePlayer();
            break;
        }
    }
}

