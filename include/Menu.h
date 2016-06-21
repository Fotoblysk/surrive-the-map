#ifndef MENU_H
#define MENU_H
#include "SFML/Graphics.hpp"

class Menu
{
    public:
        void virtual render(sf::RenderWindow& window)=0;
        int virtual getNumberOfMenuChoices()=0;
        virtual ~Menu();
        virtual sf::Text*& getSelectedTextPtr()=0;
        virtual sf::Text& getMenuText(int i)=0;
    protected:

    private:
};

#endif // MENU_H
