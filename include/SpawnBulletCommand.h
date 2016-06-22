#ifndef SPAWNBULLETCOMMAND_H
#define SPAWNBULLETCOMMAND_H
#include "Command.h"
#include "Game.h"
#include "Player.h"
#include "SFML/System/Vector2.hpp"

class SpawnBulletCommand : public Command
{
    public:
        SpawnBulletCommand(Engine* engine_in, sf::Vector2f speed_in, sf::RenderWindow& window_in, Actor* actor_in);
        void execute()override;
        virtual ~SpawnBulletCommand();
    protected:

    private:
        Actor* actor;
        sf::RenderWindow& window;
        Engine* engine;
        sf::Vector2f speed;
        GeneralTools::Direction direction;
};

#endif // SPAWNBULLETCOMMAND_H
