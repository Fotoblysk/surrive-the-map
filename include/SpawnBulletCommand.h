#ifndef SPAWNBULLETCOMMAND_H
#define SPAWNBULLETCOMMAND_H
#include "Command.h"
#include "Game.h"
#include "Player.h"
#include "SFML/System/Vector2.hpp"

class SpawnBulletCommand : public Command
{
    public:
        SpawnBulletCommand(Game& game_in, sf::Vector2f speed_in);
        void execute()override;
        virtual ~SpawnBulletCommand();
    protected:
        Player* actor;
        sf::Vector2f speed;
    private:
        Game& game;
        GeneralTools::Direction direction;
};

#endif // SPAWNBULLETCOMMAND_H
