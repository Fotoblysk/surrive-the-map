#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "../debugging_tolls.h"

class GameState
{
    public:
        enum GameStateStatus{MenuState, PlaySingleState, EndState};
        GameState();
        void changeState(GameState::GameStateStatus new_status);
        virtual ~GameState();
        GameStateStatus getState();
    protected:
    private:
        GameStateStatus game_state_status;
};

#endif // GAMESTATE_H
