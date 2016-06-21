#include "Player.h"
#include "../debugging_tolls.h"
Player::Player()
{
    acceleration.x = 0;
    acceleration.y = 0;
    speed.x = 0;
    speed.y = 0;
    setFillColor(sf::Color::Red);
    setRadius(20.0f);
    shoot_delay = 0;
}

Player::~Player()
{
    //dtor
}

void Player::update(){
    if((acceleration.y < 0 && speed.y > -MAX_SPEED) || (acceleration.y > 0 && speed.y < MAX_SPEED) )
        speed.y += acceleration.y;
    if((acceleration.x < 0 && speed.x > -MAX_SPEED) || (acceleration.x > 0 && speed.x < MAX_SPEED) )
        speed.x += acceleration.x;
    this->GameObject::update();
    move(speed);
    shotDelayUpdate();
}
void Player::shotDelayUpdate(){
    if(shoot_delay > 0)
    {
        shoot_delay--;
    }
}
bool Player::tryToShoot(){
    if(shoot_delay == 0)
    {
        shoot_delay = static_cast<const int>(1*0.1/0.01666666666);
        return true;
    }else{
        return false;
    }
}
void Player::accelerationStop(){
    acceleration.x = 0;
    acceleration.y = 0;
}
sf::Vector2f Player::getSpeed(){
    return speed;
}

void Player::render(sf::RenderWindow& window){
    window.draw(*this);
}

void Player::defaultAccelerationChangeMove(GeneralTools::Direction direction){
    switch(direction){
        case GeneralTools::Direction::Right :
            acceleration.x = 0.01;
            break;
        case GeneralTools::Direction::Left :
            acceleration.x = -0.01;
            break;
        case GeneralTools::Direction::Up :
            acceleration.y = -0.01;
            break;
        case GeneralTools::Direction::Down :
            acceleration.y = 0.01;
            break;
    }
}

bool Player::isObjectOnScreen(sf::RenderWindow& window){
    if(getShotStatus() == false)
        return false;//tmp
    if(getPosition().x >= -getGlobalBounds().width && getPosition().y >= -getGlobalBounds().height  &&  getPosition().x <= window.getSize().x && getPosition().y <= window.getSize().y)
        return true;
    else
        return false;
}

sf::FloatRect Player::getGlobalBounds(){
    return sf::CircleShape::getGlobalBounds();
}

void Player::move(const sf::Vector2f& offset){
    CircleShape::move(offset);
}
const sf::Vector2f& Player::getPosition()const{
    return this->CircleShape::getPosition();
}
