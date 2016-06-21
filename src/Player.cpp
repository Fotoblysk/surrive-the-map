#include "Player.h"

Player::Player()
{
    acceleration.x = 0;
    acceleration.y = 0;
    speed.x = 0;
    speed.y = 0;
    setFillColor(sf::Color::Red);
    setRadius(20.0f);
}


Player::~Player()
{
    //dtor
}
void Player::accelerationRight(){
    acceleration.x = 1;
}
void Player::accelerationLeft(){
    acceleration.x = -1;
}
void Player::accelerationUp(){
    acceleration.y = -1;
}
bool Player::isObjectOnScreen(sf::RenderWindow& window){
            if(is_dead == true)
                return false;//tmp
            if(getPosition().x >= -getGlobalBounds().width && getPosition().y >= -getGlobalBounds().height  &&  getPosition().x <= window.getSize().x && getPosition().y <= window.getSize().y)
                return true;
            else
                return false;
        }
void Player::accelerationDown(){
    acceleration.y = 1;
}/*
void Player::update(){
    speed.x += acceleration.x;
    speed.y += acceleration.y;
}*/
