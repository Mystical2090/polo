#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

static PlayLayer* g_activePlayLayer = nullptr; // my dick
static double g_lastClickTime = 0.0;

class $modify(AutoclickerFix, PlayLayer) {
public:
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects))
            return false;

        g_activePlayLayer = this;
        g_lastClickTime = 0.0;
        return true;
    }

    void update(float dt) override {
        PlayLayer::update(dt);

        if (Mod::get()->getSettingValue<bool>("enable-auto-clicker")) {
            double now = utils::time(); // Geode provides utils::time()
            if (now - g_lastClickTime > 0.05) { // every 50ms = 20 clicks per second
                if (this->m_player1) {
                    this->m_player1->pushButton(PlayerButton::Jump);
                }
                g_lastClickTime = now;
            }
        }
    }
};
