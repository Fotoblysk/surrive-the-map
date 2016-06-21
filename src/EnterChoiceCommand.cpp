#include "EnterChoiceCommand.h"
#include "QuitGameCommand.h"

EnterChoiceCommand::EnterChoiceCommand(Game& game_in):
    game(game_in)
{
    //ctor
}

EnterChoiceCommand::~EnterChoiceCommand()
{
    //dtor
}

void EnterChoiceCommand::execute(){ //TODO: HARD THIS IS BAD WAY TO MENAGE OPTIONS TO FIX , text options should specify behavior however I don't want to run game and ectr. in InputMenager/Command class
    auto current_option_index = findSelectedOnTextArray();
    switch(current_option_index)
    {
    case 0:
        game.changeState(Game::PlaySingleState);
        break;
    case 1:
        break;
    case 2:
        QuitGameCommand tmp(game);
        tmp.execute();
        break;
    }
}

int EnterChoiceCommand::findSelectedOnTextArray() //TODO: EASY fix - DRY
{
    int i = 0;
    for(i = 0; i < game.main_menu->getNumberOfMenuChoices()  &&  &game.main_menu->getMenuText(i) != game.main_menu->getSelectedTextPtr(); i++);
    return i;
}
