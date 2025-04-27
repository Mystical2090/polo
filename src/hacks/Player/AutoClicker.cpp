#include <Geode/Geode.hpp>
#include <Geode/modify/CCTouchDispatcher.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

// Global pointer to track the active PlayLayer
static PlayLayer* g_activePlayLayer = nullptr;

// Hook PlayLayer to grab the pointer when a level starts
class $modify(Autoclicker, PlayLayer) {
public:
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects))
            return false;

        g_activePlayLayer = this; // Save pointer to active PlayLayer
        return true;
    }
};

// Hook CCTouchDispatcher to simulate AutoClick
class $modify(AutoClickTouchDispatcher, CCTouchDispatcher) {
public:
    bool touchesBegan(CCSet* touches, CCEvent* event) {
        bool result = CCTouchDispatcher::touchesBegan(touches, event);

        if (Mod::get()->getSettingValue<bool>("auto-click-enabled")) {
            if (g_activePlayLayer && g_activePlayLayer->m_player1) {
                g_activePlayLayer->m_player1->pushButton(PlayerButton::Jump);
            }
        }

        return result;
    }
};
