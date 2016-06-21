#include<InputHandler.h>
#include "Engine.h"
class CollisionHandler : public InputHandler
{
    public:
        CollisionHandler(Engine& engine_in);
        virtual ~CollisionHandler();
        Command** handleInput()override;
    protected:
        Engine& engine;
    private:
};
