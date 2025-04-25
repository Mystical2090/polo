#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;

class $modify(AutoClickHack, PlayLayer) {
    void update(float dt) {
        if (Mod::get()->getSettingValue<bool>("enable-auto-click"))
            if (this->m_player1) this->m_player1->pushButton(PlayerButton::Jump);
        PlayLayer::update(dt);
    }
}; //not working 