#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
            return false;
        }
        return true;
    }
    void instantRespawnCallback(float dt) {
        this->resetLevel();
    }
    void destroyPlayer(PlayerObject* player, GameObject* obstacle) {
        PlayLayer::destroyPlayer(player, obstacle);

        bool instantRespawnEnabled = Mod::get()->getSettingValue<bool>("instant-respawn");


    void onQuit() {
        bool instantRespawnEnabled = Mod::get()->getSettingValue<bool>("instant-respawn");
        bool isDying = !m_hasCompletedLevel;

        if (instantRespawnEnabled && isDying) {
            this->resetLevel();
        } else {
            PlayLayer::onQuit();
        }
    }
    }
};
