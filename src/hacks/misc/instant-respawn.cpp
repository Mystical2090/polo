#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
    bool init(GJGameLevel* level) {
        if (!PlayLayer::init(level)) {
            return false;
        }
        return true;
    }

    void resetLevel() {
        bool instantRespawnEnabled = Mod::get()->getSettingValue<bool>("instant-respawn");
        
        if (instantRespawnEnabled && this->m_isDead) {
            this->m_isDead = false;
            
            if (this->m_player1) {
                this->m_player1->m_isDead = false;
                this->m_player1->setVisible(true);
            }
            if (this->m_player2) {
                this->m_player2->m_isDead = false;
                this->m_player2->setVisible(true);
            }
            
            this->m_hasCompletedLevel = false;
            this->m_bIsDualMode = this->m_bIsDualMode && this->m_levelSettings->m_originalIsDual;
            this->stopActionByTag(0);
            
            PlayLayer::resetLevel();
        } else {
            PlayLayer::resetLevel();
        }
    }
    
    void playerKilled(PlayerObject* player) {
        PlayLayer::playerKilled(player);
        
        bool instantRespawnEnabled = Mod::get()->getSettingValue<bool>("instant-respawn");
        
        if (instantRespawnEnabled) {
            this->template runAction(CCSequence::create(
                CCDelayTime::create(0.01f),
                CCCallFunc::create(this, callfunc_selector(PlayLayer::resetLevel)),
                nullptr
            ));
        }
    }
};

$execute {
    log::info("Instant Respawn mod has been loaded!");
}
