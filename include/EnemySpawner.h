#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H
#include "Enemy.h"
#include "SFML/Graphics.hpp"

class EnemySpawner
{
    public:
        EnemySpawner();
        virtual ~EnemySpawner();
        Enemy* update();
        Enemy* spawnEnemy();
    protected:
        int counter;
        const int spawn_delay;
    private:
};

#endif // ENEMYSPAWNER_H
