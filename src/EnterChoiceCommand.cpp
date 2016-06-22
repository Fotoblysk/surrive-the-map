#include "EnterChoiceCommand.h"
#include "QuitGameCommand.h"

EnterChoiceCommand::EnterChoiceCommand(GameState& game_state_in, Menu* menu_in):
    game_state(game_state_in),
    menu(menu_in)
{
    DEBUG_MSG("EnterChoiceCommand new"<<std::endl);
}

EnterChoiceCommand::~EnterChoiceCommand()
{
    DEBUG_MSG("EnterChoiceCommand delete"<<std::endl);
}

void EnterChoiceCommand::execute(){
    auto current_option_index = findSelectedOnTextArray();
    switch(current_option_index)
    {
    case 0:
        game_state.changeState(GameState::GameStateStatus::PlaySingleState);
        break;
    case 1:
        break;
    case 2:
        QuitGameCommand tmp(game_state);
        tmp.execute();
        break;
    }
}

int EnterChoiceCommand::findSelectedOnTextArray() //TODO: EASY fix - DRY
{
    int i = 0;
    for(i = 0; i < menu->getNumberOfMenuChoices()  &&  &menu->getMenuText(i) != menu->getSelectedTextPtr(); i++);
    return i;
}
