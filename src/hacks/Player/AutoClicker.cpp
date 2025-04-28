#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;

class $modify(Autoclicker, PlayLayer) {
    void update(float dt) {
        if (Mod::get()->getSettingValue<bool>("enable-auto-clicker")) {
            if (this->m_player1) {
                // Directly simulate player input
                this->m_player1->pushButton(0);  // 0 for jumps yay balls pennis
                this->m_player1->releaseButton(0);
            }
        }
        PlayLayer::update(dt);
    }
};
