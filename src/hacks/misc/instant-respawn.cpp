#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(InstantRespawn, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
            return false;
        }
        return true;
    }
    void destroyPlayer(PlayerObject* player, GameObject* obstacle) {
        PlayLayer::destroyPlayer(player, obstacle);

        bool instantRespawnEnabled = Mod::get()->getSettingValue<bool>("instant-respawn");
        if (instantRespawnEnabled) {
            this->resetLevel();
        }
    }
}; // not working idk
