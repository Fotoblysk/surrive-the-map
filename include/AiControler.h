#ifndef AICONTROLER_H
#define AICONTROLER_H
#include"InputHandler.h"
#include"Actor.h"
#include"Enemy.h" // so bad
#include"Bullet.h"
#include"../debugging_tolls.h"
#include"../GeneralTools.h"

class AiControler : public InputHandler
{
    public:
        AiControler(Actor*& target_in, Actor*& enemy_in, std::vector<Bullet*>& bullet_in, sf::RenderWindow& window_in):
        target(target_in),
        enemy(enemy_in),
        is_dead(false),
        bullet(bullet_in),
        window(window_in)
        {
            current_command_array = new Command*[SIZE];
        }
        virtual ~AiControler();
        Command** handleInput(){
            static bool avoiding;
            if(target != nullptr && enemy != nullptr)
            {
                const float gain = 100;
                sf::Vector2f tmp_speed(sf::Vector2f (target->getPosition()-enemy->getPosition()));
                tmp_speed=normToMaxSpeed(tmp_speed, gain);
                //DEBUG_MSG(sqrt(tmp_speed.x*tmp_speed.x+tmp_speed.y*tmp_speed.y)*30<<std::endl);
                enemy->speed = tmp_speed;
                //enemy->move(tmp_speed);
                if(bullet.size()>0){
                    for(auto i=0; i<bullet.size(); i++)
                    {
                       // DEBUG_MSG("bullet decetced"<<std::endl);
                        Bullet tmp=*bullet[i];
                        while (tmp.isObjectAlive(window) && !(enemy->getGlobalBounds().contains(tmp.getPosition())))
                            tmp.GameObject::update();
                        if(enemy->getGlobalBounds().contains(tmp.getPosition()))
                        {
                            Enemy tmp1=*dynamic_cast<Enemy*>(enemy);// so bad
                            Enemy tmp2=*dynamic_cast<Enemy*>(enemy);
                            int moves1=0;
                            int moves2=0;
                            tmp1.speed = (normToMaxSpeed(sf::Vector2f(-tmp.speed.y,tmp.speed.x), gain));
                            while (tmp1.getGlobalBounds().contains(tmp.getPosition())){
                                tmp1.GameObject::update();
                                moves1++;
                            }
                            tmp2.speed = (normToMaxSpeed(sf::Vector2f(tmp.speed.y,-tmp.speed.x), gain));
                            while (tmp2.getGlobalBounds().contains(tmp.getPosition())){
                                tmp2.GameObject::update();
                                moves2++;
                            }
                            if(enemy->decision > 0 || (moves1<moves2 && enemy->decision == 0)){
                                if(enemy->decision == 0)
                                    enemy->decision = 30;
                                //enemy->decision--;
                                enemy->speed = (normToMaxSpeed(sf::Vector2f(-tmp.speed.y, tmp.speed.x), gain));
                            }
                            else{
                                if(enemy->decision == 0)
                                    enemy->decision = -30;
                                //enemy->decision++;
                                enemy->speed = (normToMaxSpeed(sf::Vector2f(tmp.speed.y, -tmp.speed.x), gain));
                            }
                            i=bullet.size();
                           // enemy->move(-tmp_speed);

                            //DEBUG_MSG("WE WILL DIE !!!!!!"<<std::endl);
                        }
                    }
                }
            }
            return current_command_array;
        }
        sf::Vector2f normToMaxSpeed(sf::Vector2f in_vector, const float& gain){
            float x_tmp = in_vector.x;
            float y_tmp = in_vector.y;
            in_vector.x/=sqrt(x_tmp*x_tmp+y_tmp*y_tmp);
            in_vector.x*=gain;
            in_vector.x/=(1000000/TIME_STEP_AS_MICROS);
            in_vector.y/=sqrt(x_tmp*x_tmp+in_vector.y*in_vector.y);
            in_vector.y*=gain;
            in_vector.y/=(1000000/TIME_STEP_AS_MICROS);
            return in_vector;
        }
        bool is_dead;
    protected:
        float max_speed;
        Actor* target;
        Actor* enemy;
        std::vector<Bullet*>& bullet;
        sf::RenderWindow& window;
    private:
};

#endif // AICONTROLER_H
