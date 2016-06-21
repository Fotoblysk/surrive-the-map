#include "Enemy.h"
#include"../debugging_tolls.h"
Enemy::Enemy()
{
    is_dead = false;
    acceleration.x = 0;
    acceleration.y = 0;
    speed.x = 0;
    speed.y = 0;
    setFillColor(sf::Color::Green);
    setRadius(20.0f);
    //DEBUG_MSG("enemy created"<<std::endl);
}


Enemy::~Enemy()
{
//    DEBUG_MSG("enemy removed"<<std::endl);
}
void Enemy::accelerationRight(){
    acceleration.x = 0.01;
}
void Enemy::accelerationLeft(){
    acceleration.x = -0.01;
}
void Enemy::accelerationUp(){
    acceleration.y = -0.01;
}
bool Enemy::isObjectOnScreen(sf::RenderWindow& window){
    if(is_dead == true)
        return false;//tmp
    if(getPosition().x >= -getGlobalBounds().width && getPosition().y >= -getGlobalBounds().height  &&  getPosition().x <= window.getSize().x && getPosition().y <= window.getSize().y)
        return true;
    else
        return false;
}
void Enemy::accelerationDown(){
    acceleration.y = 0.01;
}/*
void Player::update(){
    speed.x += acceleration.x;
    speed.y += acceleration.y;
}*/
