#ifndef ENGINE_H
#define ENGINE_H
#include "Player.h"
#include "Command.h"
#include"Bullet.h"
#include"EnemySpawner.h"
#include"InputHandler.h"
#include"AiControler.h"
#include<vector>
class Engine
{
    public:
        Engine(sf::RenderWindow& window_in);
        virtual ~Engine();
        void update();
        void render();
        Player player;
        std::vector<Bullet*> bullet;
        std::vector<Actor*> enemy;
        std::vector<AiControler*> ai;
        Actor*& getCurrentPlayer();
        //void setCurrentPlayer();
    protected:
        Actor* current_player;
        sf::RenderWindow& window;
        EnemySpawner enemy_spawner;
        std::unique_ptr<InputHandler> collisionHandler;
    private:
};

#endif // ENGINE_H
