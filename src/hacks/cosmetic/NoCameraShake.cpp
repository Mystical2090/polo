
#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;
extern bool NoCameraShake;
class $modify (GJBaseGameLayer)
{
    void updateCamera(float delta)
    {
        if (NoCameraShake)
        {
            m_gameState.m_cameraShakeFactor = 0;
            m_gameState.m_cameraShakeEnabled = false;
        }

        GJBaseGameLayer::updateCamera(delta);
    }
};
