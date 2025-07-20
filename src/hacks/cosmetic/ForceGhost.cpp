#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

extern bool ForceGhostOn;
extern bool ForceGhostOff;
class $modify (PlayerObject)
{
    void toggleGhostEffect(GhostType state)
    {
        if (PlayLayer::get())
        {
            if (ForceGhostOn)
                state = GhostType::Enabled;

            if (ForceGhostOff)
                state = GhostType::Disabled;
        }

        PlayerObject::toggleGhostEffect(state);
    }
};
