#include "EnemySpawner.h"
#include <cstdio>
#include <ctime>
EnemySpawner::EnemySpawner():
spawn_delay(0.2*3*(1/0.01666666666))
{
    counter = spawn_delay;
    srand(time(NULL));
}
Enemy* EnemySpawner::update()
{
    counter--;
    if(! counter)
    {
        counter=spawn_delay;
        return spawnEnemy();
    }
    return nullptr;
}
Enemy* EnemySpawner::spawnEnemy()
{
    Enemy* tmp = new Enemy;
    tmp->accelerationDown();
    tmp->setPosition(sf::Vector2f(rand()%500, rand()%500));
    return tmp;
}
EnemySpawner::~EnemySpawner()
{
    //dtor
}
