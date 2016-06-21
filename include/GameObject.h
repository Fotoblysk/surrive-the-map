#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics.hpp>

class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();
        virtual void move(const sf::Vector2f& offset)=0;
        virtual const sf::Vector2f& getPosition()=0;
        virtual void update(){
            move(speed);
        }
        virtual void render(sf::RenderWindow& window)=0;
        sf::Vector2f speed;
    protected:
        sf::Vector2f acceleration;
    private:
};

#endif // GAMEOBJECT_H
