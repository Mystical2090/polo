#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;

class $modify(AutoClacker, GJBaseGameLayer) {
public:
    bool m_autoClickerEnabled = false;
    int m_frames = 0;
    int m_framesHeld = 0;
    bool m_isHeld = false;
    bool init() {
        if (!GJBaseGameLayer::init())
            return false;
        this->scheduleUpdate();
        return true;
    }

    void update(float dt) {
        GJBaseGameLayer::update(dt);
        
        auto mod = Mod::get();
        int delay = mod->getSettingValue<int>("auto-clicker-delay");
        int holdFor = mod->getSettingValue<int>("auto-clicker-holdfor");
        bool player1Enabled = mod->getSettingValue<bool>("auto-clicker-player1");
        bool player2Enabled = mod->getSettingValue<bool>("auto-clicker-player2");
        
        if (!player1Enabled && !player2Enabled)
            return;
        
        m_frames++;
        
        if (m_frames >= delay) {
            m_frames = 0;
            m_framesHeld = 0;
        }
        
        if (m_frames == 0) {
            // Perform click
            if (player1Enabled)
                this->handleButton(true, static_cast<int>(PlayerButton::Jump), true);
                
            if (player2Enabled && m_player2 && m_gameState.m_isDualMode)
                this->handleButton(true, static_cast<int>(PlayerButton::Jump), false);
                
            m_isHeld = true;
        }
        
        if (m_framesHeld >= holdFor) {
            // Release click
            if (player1Enabled)
                this->handleButton(false, static_cast<int>(PlayerButton::Jump), true);
                
            if (player2Enabled && m_player2 && m_gameState.m_isDualMode)
                this->handleButton(false, static_cast<int>(PlayerButton::Jump), false);
                
            m_isHeld = false;
        }
        
        if (m_isHeld)
            m_framesHeld++;
    }
};
