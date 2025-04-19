#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(NoclipPlayer, PlayerObject) {
    void destroyPlayer() {
        if (Mod::get()->getSettingValue<bool>("noclip")) {
            // dont die when you die
            return;
        }

        // die when you die
        PlayerObject::destroyPlayer();
    }
};
