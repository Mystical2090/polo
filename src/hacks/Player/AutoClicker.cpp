#include <Geode/Geode.hpp>
#include <Geode/modify/CCTouchDispatcher.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;

// abcdefghijklmnopqrst
static PlayLayer* g_activePlayLayer = nullptr;

class $modify(Autoclicker, PlayLayer) {
public:
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects))
            return false;

        g_activePlayLayer = this;
        return true;
    }
};

// Hook CCTouchDispatcher to simulate a click
class $modify(AutoClickTouchDispatcher, CCTouchDispatcher) {
public:
    void touchesBegan(CCSet* touches, CCEvent* event) override {
        CCTouchDispatcher::touchesBegan(touches, event); // Just call, no assignment

        if (Mod::get()->getSettingValue<bool>("enable-auto-clicker")) {
            if (g_activePlayLayer && g_activePlayLayer->m_player1) {
                g_activePlayLayer->m_player1->pushButton(PlayerButton::Jump);
            }
        }
    }
};
