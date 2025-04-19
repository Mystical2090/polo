#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(NoclipPlayer, PlayerObject) {
    void collided(cocos2d::CCObject* obj) {
        if (Mod::get()->getSettingValue<bool>("enable-noclip")) {
            // dont die when die
            return;
        }

        // die when die
        PlayerObject::collided(obj);
    }
};
