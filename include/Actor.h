#ifndef ACTOR_H
#define ACTOR_H
#include "GameObject.h"

class Actor : public GameObject
{
    public:
        Actor () {}
        virtual ~Actor();
        virtual void defaultAccelerationChangeMove(GeneralTools::Direction direction)=0;
        virtual sf::FloatRect getGlobalBounds()=0;
        virtual bool isObjectOnScreen(sf::RenderWindow& window)=0;
        virtual bool getShotStatus()const;
        virtual void getShotStatus(bool new_alive_status);
        virtual bool tryToShoot(){return false;}
    protected:
        bool shot_status;
        float max_speed; // not used yet
    private:
};

#endif // ACTOR_H
