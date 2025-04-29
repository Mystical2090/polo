// FLERO CODE BE ON FIRE RN
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(AutoClickLayer, PlayLayer) {
    void update(float dt) {
        if (Mod::get()->getSettingValue<bool>("enable-auto-clicker"))
            if (this->m_player1) this->handleButton(0, true, true);
        PlayLayer::update(dt);
    }
};
