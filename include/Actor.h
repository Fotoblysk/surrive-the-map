#ifndef ACTOR_H
#define ACTOR_H
#include "GameObject.h"

class Actor : public GameObject
{
    public:
        Actor():decision(0){}
        virtual ~Actor();
        float max_speed;
        virtual void accelerationRight()=0;
        virtual void accelerationLeft()=0;
        virtual void accelerationUp()=0;
        virtual void accelerationDown()=0;
        virtual sf::FloatRect getGlobalBounds()=0;
        bool is_dead;
        virtual bool isObjectOnScreen(sf::RenderWindow& window)=0;
        int decision;
    protected:
    private:
};

#endif // ACTOR_H
