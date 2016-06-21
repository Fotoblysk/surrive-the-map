#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include "../debugging_tolls.h"
#include "GameObject.h"

class Bullet : public GameObject , public sf::CircleShape
{
    public:
        Bullet(sf::Vector2f position_in, sf::Vector2f speed_in);
        virtual ~Bullet();
        void render(sf::RenderWindow& window)override;
        const sf::Vector2f& getPosition()const override;
        void move(const sf::Vector2f& offset)override;
        bool isOnRenderArea(sf::RenderWindow& window)const;
    protected:
};

#endif // BULLET_H
