#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#define MAX_SPEED 100
#include "Actor.h"

class Enemy : public Actor, public sf::CircleShape
{
    public:
        virtual sf::FloatRect getGlobalBounds()override{return sf::CircleShape::getGlobalBounds();};
        virtual void move(const sf::Vector2f& offset){
            CircleShape::move(offset);
        }
        virtual void render(sf::RenderWindow& window){
            window.draw(*this);
        }
        const sf::Vector2f& getPosition()const override;
        Enemy();
        void defaultAccelerationChangeMove(GeneralTools::Direction direction);
        void accelerationLeft();
        void accelerationDown();
        void accelerationUp();
        void update()override;
        sf::Vector2f getSpeed(){
            return speed;
        }
        virtual ~Enemy();
        bool isObjectOnScreen(sf::RenderWindow& window)override;
    protected:
        int notshotable;
    private:

};

#endif // PLAYER_H
