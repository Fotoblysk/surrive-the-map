#include "MainMenu.h"
int MainMenu::getNumberOfMenuChoices(){
return NUMBER_OF_MENU_CHOICES;
}
void MainMenu::render(sf::RenderWindow& window){
    for(auto i=0; i<NUMBER_OF_MENU_CHOICES; i++)
        window.draw(menu_text[i]);
}

MainMenu::MainMenu() :
NUMBER_OF_MENU_CHOICES(3),
menu_text(new sf::Text[NUMBER_OF_MENU_CHOICES]),
selected_text(nullptr)
{
    font.loadFromFile("fonts/goodfoot.ttf");
    menu_text[0].setString(std::string("Play"));
    menu_text[1].setString(std::string("Settings"));
    menu_text[2].setString(std::string("Quit"));
    for(auto i=0; i<NUMBER_OF_MENU_CHOICES; i++)
    {
        menu_text[i].setFont(font);
        menu_text[i].setCharacterSize(24);
        menu_text[i].setColor(sf::Color::Red);
        menu_text[i].setStyle(sf::Text::Bold | sf::Text::Underlined);
        menu_text[i].setPosition(0, i * (menu_text[i].getGlobalBounds().height + 10));
    }
}

MainMenu::~MainMenu()
{
    //dtor
}
sf::Text*& MainMenu::getSelectedTextPtr(){
    return selected_text;
}
sf::Text& MainMenu::getMenuText(int i)
{
    return menu_text[i];
}
