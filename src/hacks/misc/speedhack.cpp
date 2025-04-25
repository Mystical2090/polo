#include <Geode/Geode.hpp>
#include <Geode/modify/CCScheduler.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include "Speedhack.hpp"

class $modify (CCScheduler)
{
    virtual void update(float dt)
    {
        dt = speedhackLogic(dt);

        CCScheduler::update(dt);
    }
};
