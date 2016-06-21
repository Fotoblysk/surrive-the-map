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
        virtual sf::FloatRect getGlobalBounds()override{return sf::CircleShape::getGlobalBounds();};
        virtual void move(const sf::Vector2f& offset){
            CircleShape::move(offset);
        }
        virtual void render(sf::RenderWindow& window){
            window.draw(*this);
        }
        const sf::Vector2f& getPosition()override{return this->CircleShape::getPosition();}
        void accelerationRight()override;
        void accelerationDown()override;
        void accelerationLeft()override;
        void accelerationUp()override;
        void update(){
            if((acceleration.y < 0 && speed.y > -MAX_SPEED) || (acceleration.y > 0 && speed.y < MAX_SPEED) )
                speed.y += acceleration.y;
            if((acceleration.x < 0 && speed.x > -MAX_SPEED) || (acceleration.x > 0 && speed.x < MAX_SPEED) )
                speed.x += acceleration.x;
        }
        void accelerationStop(){
            acceleration.x = 0;
            acceleration.y = 0;
        }
        sf::Vector2f getAcceleration(){
            return speed;
        }
        bool isObjectOnScreen(sf::RenderWindow& window);
        virtual ~Player();
        sf::Vector2f acceleration;
        sf::Vector2f speed;
        int notshotable;
    protected:

    private:

};

#endif // PLAYER_H
