#ifndef MAINMENU_H
#define MAINMENU_H
#include <memory>
#include <Menu.h>


class MainMenu : public Menu
{
    public:
        int getNumberOfMenuChoices()override;
        void render(sf::RenderWindow& window)override;
        MainMenu();
        virtual ~MainMenu();
        sf::Text*& getSelectedTextPtr()override;
        sf::Text& getMenuText(int i)override;
    protected:

        //TODO: MEDIUM This can and should be in a base class.
        //'
        const int NUMBER_OF_MENU_CHOICES;
        std::unique_ptr<sf::Text[]> menu_text;
        sf::Font font;
        sf::Text* selected_text;
        //'

    private:
};

#endif // MAINMENU_H
