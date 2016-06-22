#include "MoveSelectionCommand.h"
#include"../debugging_tolls.h"
MoveSelectionCommand::MoveSelectionCommand(Menu* menu_in, GeneralTools::Direction direction_in) :
menu(menu_in),
direction(direction_in)
{
    DEBUG_MSG("Creating MoveSelectionCommand direction = "<<direction<<std::endl);
}


MoveSelectionCommand::~MoveSelectionCommand()
{

}
void MoveSelectionCommand::execute(){
    switch(direction){
        case GeneralTools::Down :
            if(menu->getSelectedTextPtr() == nullptr)
                menu->getSelectedTextPtr() = &menu->getMenuText(0);
            else{
                //un-hilighting last one
                menu->getSelectedTextPtr() -> setColor(sf::Color::Red);

                //moving selected text no next one or first one if previous was last one (NUMBER_OF_MENU_CHOICES-1)
                menu->getSelectedTextPtr() = &menu->getMenuText((findSelectedOnTextArray() + 1) % menu->getNumberOfMenuChoices());
            }
            //hilighting current one
            menu->getSelectedTextPtr() -> setColor(sf::Color::Yellow);
            break;
        case GeneralTools::Up :
            if(menu->getSelectedTextPtr() == nullptr)
                menu->getSelectedTextPtr() = &menu->getMenuText(menu->getNumberOfMenuChoices()-1);
            else{
                //un-hilighting last one
                menu->getSelectedTextPtr() -> setColor(sf::Color::Red);

                //moving selected text no next one or first one if previous was last one (NUMBER_OF_MENU_CHOICES-1)
                menu->getSelectedTextPtr() = &menu->getMenuText((findSelectedOnTextArray() - 1 + menu->getNumberOfMenuChoices()) % menu->getNumberOfMenuChoices());
            }
            //hilighting current one
            menu->getSelectedTextPtr() -> setColor(sf::Color::Yellow);
            break;
    }
}
int MoveSelectionCommand::findSelectedOnTextArray()
{
    int i = 0;
    for(i = 0; i < menu->getNumberOfMenuChoices()  &&  &menu->getMenuText(i) != menu->getSelectedTextPtr(); i++);
    return i;
}

