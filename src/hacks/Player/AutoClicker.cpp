#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;

class $modify(AutoClickerlayer, PlayLayer) {
    void update(float dt) {
        if (Mod::get()->getSettingValue<bool>("enable-auto-clicker")) {
            if (this->m_player1) {
                this->m_player1->pushButton(PlayerButton::Jump);
                this->m_player1->releaseButton(PlayerButton::Jump);
            }
        }
        PlayLayer::update(dt);
    }
};
