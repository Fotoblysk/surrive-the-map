#include "Engine.h"
#include "CollisionHandler.h"
Engine::Engine(sf::RenderWindow& window_in):
window(window_in),
current_player(&player),
collisionHandler(new CollisionHandler(*this))
{
    //ctor
}

Engine::~Engine()
{
    //dtor
}

void Engine::update(){
    collisionHandler->handleInput();
    Actor* tmp = enemy_spawner.update();
    AiControler* tmp_ai = new AiControler(current_player, tmp, bullet, window);
    if(tmp)
    {
        enemy.push_back(tmp);
        ai.push_back(tmp_ai);
    }
    player.CircleShape::move(player.getSpeed().x * TIME_STEP_AS_MICROS/1000000.f, player.getSpeed().y *TIME_STEP_AS_MICROS/1000000.f);
    player.update();
    if(player.acceleration.x < 0.001 && player.acceleration.x > -0.001)
        player.speed.x/=1.1;
    if(player.acceleration.y < 0.001 && player.acceleration.y > -0.001)
        player.speed.y/=1.1;
    player.accelerationStop();
    for(auto i = 0; i<bullet.size(); i++)
        if(bullet[i])
        {
            bullet[i]->GameObject::update();
            if(bullet[i]->isOnRenderArea(window))
                window.draw(*bullet[i]);
            else{
                std::swap(bullet[i],bullet[bullet.size()-1]);
                delete bullet[bullet.size()-1];
                bullet.pop_back();
            }
        }
    for(auto i = 0; i<enemy.size(); i++)
        if(enemy[i])
        {
          //  enemy[i] -> update();
            ai[i] -> handleInput();
            enemy[i]->update();
            if(enemy[i] -> isObjectOnScreen(window)){
                enemy[i]->render(window);
            }
            else{
                enemy[enemy.size()-1]->render(window);
                std::swap(enemy[i],enemy[enemy.size()-1]);
                std::swap(ai[i],ai[enemy.size()-1]);
                delete ai[ai.size()-1];
                delete enemy[enemy.size()-1];
                ai.pop_back();
                enemy.pop_back();
            }
        }
}

void Engine::render(){
    window.draw(player);
}
