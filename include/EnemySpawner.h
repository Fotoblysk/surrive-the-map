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
        const int spawn_delay;
        int counter;
    protected:

    private:
};

#endif // ENEMYSPAWNER_H
