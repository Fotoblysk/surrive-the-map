#ifndef GAME_H
#define GAME_H
#include"../debugging_tolls.h"
#include<SFML/Graphics.hpp>
#include"InputHandler.h"
#include"Engine.h"
#include"Menu.h"
#include"GameState.h"
#include<string>
#include<memory>
/*!
 * \brief Game main class. Class which is used run engine.
 * This class will menage menu and settings
*/
class Game
{
    public:
        Game(sf::RenderWindow& window_in);     ///< Initialization of RenderWindow& window - main window of the game.
        virtual ~Game();                       ///< Runs StartGame() function
        sf::RenderWindow& getRenderWindow();
        void run();
        void startSinglePlayer();
        std::unique_ptr <Engine> engine;
        GameState game_state;
    protected:

    private:
        std::unique_ptr <Menu> main_menu;
        void menu();
        sf::RenderWindow& window;           ///<Main game window
        std::unique_ptr <InputHandler> input;
        void stateMachine();
};

#endif // GAME_H
