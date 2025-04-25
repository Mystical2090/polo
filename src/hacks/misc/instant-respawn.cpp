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
    
    void resetLevel() {
        PlayLayer::resetLevel();
    }
    
    void playerKill() {
        bool instantRespawnEnabled = Mod::get()->getSettingValue<bool>("instant-respawn");
        
        PlayLayer::playerKill();
        
        if (instantRespawnEnabled) {
            this->scheduleOnce([this](float) {
                this->resetLevel();
            }, 0.01f, "instant_respawn");
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
