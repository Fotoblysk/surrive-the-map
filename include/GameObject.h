#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics.hpp>
#include "../GeneralTools.h"
class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();
        virtual void move(const sf::Vector2f& offset)=0;
        virtual const sf::Vector2f& getPosition()const=0;
        virtual void update(){
            move(speed);
        }
        virtual void render(sf::RenderWindow& window)=0;
        sf::Vector2f speed;
        sf::Vector2f acceleration;
    protected:
    private:
};

#endif // GAMEOBJECT_H
