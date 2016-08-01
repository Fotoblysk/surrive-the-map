#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#define MAX_SPEED 100
#include "Actor.h"
class Player : public Actor, public sf::CircleShape
{
    public:
        Player();
        sf::FloatRect getGlobalBounds()override;
        void move(const sf::Vector2f& offset);
        void render(sf::RenderWindow& window);
        const sf::Vector2f& getPosition()const override;
        void defaultAccelerationChangeMove(GeneralTools::Direction direction)override;
        void update();
        void accelerationStop();
        sf::Vector2f getSpeed();
        bool isObjectOnScreen(sf::RenderWindow& window);
        virtual ~Player();
        virtual bool tryToShoot()override;
    private:
        unsigned int shoot_delay;
        void shotDelayUpdate();
};

#endif // PLAYER_H
