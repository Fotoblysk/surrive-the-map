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
        const sf::Vector2f& getPosition()override{return this->CircleShape::getPosition();}
        Enemy();
        void accelerationRight();
        void accelerationLeft();
        void accelerationDown();
        void accelerationUp();
        void update()override{
           /* if((acceleration.y < 0 && speed.y > -MAX_SPEED) || (acceleration.y > 0 && speed.y < MAX_SPEED) )
                speed.y += acceleration.y;
            if((acceleration.x < 0 && speed.x > -MAX_SPEED) || (acceleration.x > 0 && speed.x < MAX_SPEED) )
                speed.x += acceleration.x;*/
            move(speed);
        }
        void accelerationStop(){
            acceleration.x = 0;
            acceleration.y = 0;
        }
        sf::Vector2f getAcceleration(){
            return speed;
        }
        virtual ~Enemy();
        int notshotable;
        bool isObjectOnScreen(sf::RenderWindow& window)override;
    protected:

    private:

};

#endif // PLAYER_H
