#ifndef GAME_H
#define GAME_H
#include"../debugging_tolls.h"
#include<SFML/Graphics.hpp>
#include"InputHandler.h"
#include"Engine.h"
#include"Menu.h"
#include<string>
#include<memory>
/*!
 * \brief Game main class. Class which is used run engine.
 * This class will menage menu and settings
*/
class Game
{
    public:
        enum GameState{MenuState, PlaySingleState, EndState};
        Game(sf::RenderWindow& window_in);     ///< Initialization of RenderWindow& window - main window of the game.
        virtual ~Game();                       ///< Runs StartGame() function
        void changeState(GameState new_state);
        sf::RenderWindow& getRenderWindow();
        void run();
        void startSinglePlayer();
        std::unique_ptr <Menu> main_menu;
        std::unique_ptr <Engine> engine;
    protected:

    private:
        void menu();
        sf::RenderWindow& window;           ///<Main game window
        std::unique_ptr <InputHandler> menu_input;
        GameState state;
        void stateMachine();
};

#endif // GAME_H
