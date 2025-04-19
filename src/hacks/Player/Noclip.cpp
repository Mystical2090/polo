#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

// Only apply this mod if the setting is enabled
$execute {
    return Mod::get()->getSettingValue<bool>("enable-noclip");
}

class $modify(NoclipHack, PlayLayer) {
    void update(float dt) {
        if (this->m_player1) {
            this->m_player1->m_isDead = false;
        }
        PlayLayer::update(dt);
    }
};
