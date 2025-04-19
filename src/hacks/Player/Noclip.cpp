#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(NoclipPlayer, PlayerObject) {
    bool checkCollisions(CCRect rect) {
        if (Mod::get()->getSettingValue<bool>("enable-noclip")) {
            return false; // dis makes you not die 
        }
        return PlayerObject::checkCollisions(rect); // dis makes you die
    }
};
