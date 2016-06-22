/*! \file main.cpp
 *
 * \brief only main(). mainpage in.
 *
 * \author  Fotoblysk
 *
 * \date  2016/03/18 12:00
*/

/*! \mainpage
 * \brief Empty-SFML project - dll linking.
 *
 * \note with gh-pages :V
 *
 * \author  Fotoblysk
 *
 * \version $Revision: 0.01 $
 *
 * \date  2016/03/13 21:44:00
 *
 * Contact: fotoblysk@fejm.pl
 *
 * Created on: Sun Mar 13 21:44:00 2016
 *
 * $Id: Empty-SFML-dll,v 1.00  21:44:00 bv Exp Fotoblysk$
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

/*
    // TODO (#FOTO): 1PIORITY numeration is random
        1. Replace pointers to smart pointers and end memory leaks.
        2. MoveSelectionDown and MoveSelectionUp can and should be 1 class.
        3. Engine should be abstract and used single and multi-player mode.
        4. Think  how will multi-mode communicate with network in different thread.
        5. All menu like classes should use same commands and menu class.
        6. Menu class should be deleted before running game. However I don't want to give up current input handling model.
        Think about it.
        7. DRY rework.
        8. Doxygen at least for diagrams.
        9. VS migration - not sure
        10. GitHub:
        -readme
        -git ignore
        -database for architecturePlaning for the game.
        - gh-pages with doxygen
        11. Documentation at least classes, public methods and methods witch are likely to be changed.
        12. Rendering and physics separation for instance rendering.
        13. Replace public vars to getters and setters - SHAME.
        14. Refactoring of whole AiController - usage of command, Spawners - prototype pattern, and ColisionHandler -(checking for all collisions and have different behavior depending on objects collided) classes - SHAME.
        15. gh-pages branch Doxygen diagram update - SHAME.
        16. NOT SURE Replace Command class with pointers to functions.
*/

/*!
 * \brief Runs RenderWindow. Runs game.
*/
int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(500, 500), "surrive-the-map", sf::Style::Fullscreen, settings);
    Game game(window);
    game.run();
    return EXIT_SUCCESS;
}
