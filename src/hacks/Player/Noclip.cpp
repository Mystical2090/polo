#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(NoclipPlayer, PlayerObject) {
    void destroyPlayer() override {
        if (Mod::get()->getSettingValue<bool>("noclip")) {
            // dont die when die
            return;
        }

        // die when die
        PlayerObject::destroyPlayer();
    }
};
