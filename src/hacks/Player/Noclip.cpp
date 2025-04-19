#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(NoclipPlayer, PlayerObject) {
    bool checkCollisions(CCRect rect) {
        if (Mod::get()->getSettingValue<bool>("enable-noclip")) {
            return false; // skip collision
        }
        return PlayerObject::checkCollisions(rect); // original behavior
    }
};
