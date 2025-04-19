#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>\

using namespace geode::prelude;

$execute {
    if (!Mod::get()->getSettingValue<bool>("enable-noclip")) {
        return Mod::Result::Error("Noclip is disabled in settings");
    }
    return Mod::Result::Success;
}

class $modify(NoclipHack, PlayLayer) {
    void update(float dt) {
        if (this->m_player1) {
            this->m_player1->m_isDead = false;
        }
        PlayLayer::update(dt);
    }
};
