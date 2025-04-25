#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;

class $modify(FlyHack, PlayLayer) {
    void update(float dt) {
        if (Mod::get()->getSettingValue<bool>("enable-fly")) // dis make it
            if (this->m_player1) this->m_player1->m_yVelocity = 14.0f; // dis make it
        PlayLayer::update(dt);
    }
}; // not working
