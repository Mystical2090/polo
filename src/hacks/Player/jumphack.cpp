#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
using namespace geode::prelude;

extern bool jumpHackEnabled;

class $modify (GJBaseGameLayer)
{
    virtual void update(float dt)
    {
        if (jumpHackEnabled) {
        {
            if (m_player1)
                m_player1->m_isOnGround = true;

            if (m_player2)
                m_player2->m_isOnGround = true;
        }

        GJBaseGameLayer::update(dt);
        }
    }
};
