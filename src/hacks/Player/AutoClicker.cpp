#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;
// oh nah im not dealing with this chatgpt code sorry mr mystic
class $modify(PlayLayer) {
    bool m_isAutoClicking = false;
    float m_clickTimer = 0.0f;
    const float CLICK_INTERVAL = 0.05f;

    bool init(GJGameLevel* level) {
        if (!PlayLayer::init(level))
            return false;
            
        // Initialize auto-click state
        m_isAutoClicking = Mod::get()->getSettingValue<bool>("enable-auto-clicker");
        
        // Log initialization for debugging
        log::info("Auto-clicker initialized: {}", m_isAutoClicking ? "enabled" : "disabled");
        
        return true;
    }
    
    void update(float dt) {
        PlayLayer::update(dt);
        
        // Check if auto-clicker is enabled through mod settings
        m_isAutoClicking = Mod::get()->getSettingValue<bool>("enable-auto-clicker");
        
        // Only proceed if the player exists and auto-click is enabled
        if (m_isAutoClicking && m_player1 && !m_isDead) {
            // Timer-based approach to control click frequency
            m_clickTimer += dt;
            if (m_clickTimer >= CLICK_INTERVAL) {
                log::debug("Auto-clicking");
                
                // Perform the click - using direct player control
                this->pushButton(true, 0);
                
                // Reset the timer
                m_clickTimer = 0.0f;
            }
        }
    }
};
