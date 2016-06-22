#include "SpawnBulletCommand.h"
#include "cmath"
#define BULLETTO_SPEED 10

SpawnBulletCommand::SpawnBulletCommand(Engine* engine_in, sf::Vector2f speed_in, sf::RenderWindow& window_in, Actor* actor_in) :
engine(engine_in),
speed(speed_in),
window(window_in),
actor(actor_in)
{

}

SpawnBulletCommand::~SpawnBulletCommand()
{

}
void SpawnBulletCommand::execute(){
    if(actor->tryToShoot()){
        sf::Vector2f tmp_center_position(actor->getPosition());
        tmp_center_position.x+=actor->getGlobalBounds().height/2 -5; //radius
        tmp_center_position.y+=actor->getGlobalBounds().width/2 -5; //radius
        sf::Vector2f mouse_position (sf::Mouse::getPosition(window));
        mouse_position.x -= 5; //radius
        mouse_position.y -= 5; //radius
        sf::Vector2f tmp_speed(mouse_position - tmp_center_position);
        float x_tmp = tmp_speed.x;
        tmp_speed.x/=sqrt(x_tmp*x_tmp+tmp_speed.y*tmp_speed.y);
        tmp_speed.x*=BULLETTO_SPEED;
        tmp_speed.y=tmp_speed.y/sqrt(x_tmp*x_tmp+tmp_speed.y*tmp_speed.y);
        tmp_speed.y*=BULLETTO_SPEED;
//        DEBUG_MSG(sqrt(tmp_speed.x*tmp_speed.x+tmp_speed.y*tmp_speed.y));
        engine->bullet.push_back(new Bullet(tmp_center_position,tmp_speed));
    }
}


