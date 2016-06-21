#ifndef AICONTROLER_H
#define AICONTROLER_H
#include"InputHandler.h"
#include"Actor.h"
#include"Enemy.h" // so bad
#include"Bullet.h"
#include"../debugging_tolls.h"
#include"../GeneralTools.h"

class AiControler : public InputHandler
{
    public:
        AiControler(Actor*& target_in, Actor*& enemy_in, std::vector<Bullet*>& bullet_in, sf::RenderWindow& window_in);
        virtual ~AiControler();
        Command** handleInput();
    protected:

    private:
        sf::Vector2f normToMaxSpeed(sf::Vector2f in_vector, const float& gain);
        bool is_dead;
        float max_speed;
        Actor* target;
        Actor* enemy;
        std::vector<Bullet*>& bullet;
        sf::RenderWindow& window;
        int decision;
};

#endif // AICONTROLER_H
