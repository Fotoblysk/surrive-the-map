#include "Enemy.h"
#include"../debugging_tolls.h"
Enemy::Enemy()
{
    getShotStatus(true);
    acceleration.x = 0;
    acceleration.y = 0;
    speed.x = 0;
    speed.y = 0;
    setFillColor(sf::Color::Green);
    setRadius(20.0f);
    //DEBUG_MSG("enemy created"<<std::endl);
}


Enemy::~Enemy(){
//    DEBUG_MSG("enemy removed"<<std::endl);
}

const sf::Vector2f& Enemy::getPosition()const{
    return this->sf::CircleShape::getPosition();
}

void Enemy::defaultAccelerationChangeMove(GeneralTools::Direction direction){
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
void Enemy::accelerationLeft(){
    acceleration.x = -0.01;
}
void Enemy::accelerationUp(){
    acceleration.y = -0.01;
}
bool Enemy::isObjectOnScreen(sf::RenderWindow& window){
    if(getShotStatus() == false)
        return false;//tmp
    if(getPosition().x >= -getGlobalBounds().width && getPosition().y >= -getGlobalBounds().height  &&  getPosition().x <= window.getSize().x && getPosition().y <= window.getSize().y)
        return true;
    else
        return false;
}
void Enemy::accelerationDown(){
    acceleration.y = 0.01;
}

void Enemy::update(){
    move(speed);
}
