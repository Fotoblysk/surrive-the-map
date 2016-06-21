#include "Bullet.h"
#include "../debugging_tolls.h"

Bullet::~Bullet()
{
   // DEBUG_MSG("removing bulletto"<<std::endl);
}
Bullet::Bullet(sf::Vector2f position_in, sf::Vector2f speed_in)
{
    speed = speed_in;
    setPosition(position_in);
    setRadius(5);
    setFillColor(sf::Color::Blue);
    //DEBUG_MSG("bullet created"<<std::endl);
}
void Bullet::render(sf::RenderWindow& window){
    window.draw(*this);
}
bool Bullet::isOnRenderArea(sf::RenderWindow& window)const{
    if(getPosition().x >= -getGlobalBounds().width && getPosition().y >= -getGlobalBounds().height  &&  getPosition().x <= window.getSize().x && getPosition().y <= window.getSize().y)
        return true;
    else
        return false;
}

void Bullet::move(const sf::Vector2f& offset){
    sf::CircleShape::move(offset);
}

const sf::Vector2f& Bullet::getPosition()const{
    return this->CircleShape::getPosition();
}
