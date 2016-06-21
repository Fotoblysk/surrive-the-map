#include "SpawnBulletCommand.h"
#include "cmath"
#define BULLETTO_SPEED 10

SpawnBulletCommand::SpawnBulletCommand(Game& game_in, sf::Vector2f speed_in):
game(game_in),
speed(speed_in),
actor(&game_in.engine->player)
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
        sf::Vector2f mouse_position (sf::Mouse::getPosition(game.getRenderWindow()));
        mouse_position.x -= 5; //radius
        mouse_position.y -= 5; //radius
        sf::Vector2f tmp_speed(mouse_position - tmp_center_position);
        float x_tmp = tmp_speed.x;
        tmp_speed.x/=sqrt(x_tmp*x_tmp+tmp_speed.y*tmp_speed.y);
        tmp_speed.x*=BULLETTO_SPEED;
        tmp_speed.y=tmp_speed.y/sqrt(x_tmp*x_tmp+tmp_speed.y*tmp_speed.y);
        tmp_speed.y*=BULLETTO_SPEED;
//        DEBUG_MSG(sqrt(tmp_speed.x*tmp_speed.x+tmp_speed.y*tmp_speed.y));
        game.engine->bullet.push_back(new Bullet(tmp_center_position,tmp_speed));
    }
}


