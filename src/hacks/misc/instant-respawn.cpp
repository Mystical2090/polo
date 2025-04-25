#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

void instantRespawnCallback(CCObject* sender) {
    auto playLayer = static_cast<PlayLayer*>(sender);
    if (playLayer) {
        playLayer->resetLevel();
    }
}

class $modify(PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
            return false;
        }
        return true;
    }
    
    void destroyPlayer(PlayerObject* player, GameObject* obstacle) {
        PlayLayer::destroyPlayer(player, obstacle);
        
        bool instantRespawnEnabled = Mod::get()->getSettingValue<bool>("instant-respawn");
        
        if (instantRespawnEnabled && !this->m_hasCompletedLevel) {
            this->scheduleOnce(schedule_selector(instantRespawnCallback), 0.01f);
        }
    }
    
    void onQuit() {
        bool instantRespawnEnabled = Mod::get()->getSettingValue<bool>("instant-respawn");
        bool isDying = !this->m_hasCompletedLevel;
        
        if (instantRespawnEnabled && isDying) {
            this->resetLevel();
        } else {
            PlayLayer::onQuit();
        }
    }
};

$execute {
    log::info("Instant Respawn mod has been loaded!");
}
