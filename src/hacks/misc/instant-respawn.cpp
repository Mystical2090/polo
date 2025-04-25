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
        bool instantRespawnEnabled = Mod::get()->getSettingValue<bool>("instant-respawn");
        
        if (instantRespawnEnabled && this->m_isGameplayActive && !this->m_hasCompletedLevel) {
            this->stopAllActions();
            
            PlayLayer::resetLevel();
        } else {
            PlayLayer::resetLevel();
        }
    }
};

class $modify(GJBaseGameLayer) {
    void destroyPlayer(PlayerObject* player, bool doDeathActions) {
        bool instantRespawnEnabled = Mod::get()->getSettingValue<bool>("instant-respawn");
        
        GJBaseGameLayer::destroyPlayer(player, doDeathActions);
        
        if (instantRespawnEnabled && doDeathActions) {
            auto playLayer = static_cast<PlayLayer*>(this);
            if (playLayer && !playLayer->m_hasCompletedLevel) {
                playLayer->scheduleOnce([playLayer](float) {
                    playLayer->resetLevel();
                }, 0.01f, "instant_respawn");
            }
        }
    }
};

$execute {
    log::info("Instant Respawn mod has been loaded!");
}
