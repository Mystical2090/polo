#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;

class $modify(NoclipHack, PlayLayer) {
    void update(float dt) {
    auto myBool = Mod::get()->getSettingValue<bool>("my-bool-setting");
    auto myInt  = Mod::get()->getSettingValue<int64_t>("my-int-setting");
        if (Mod::get()->getSettingValue<bool>("true"))
            if (this->m_player1) this->m_player1->m_isDead = false;
        PlayLayer::update(dt);
    }
};

void loadPlayerHacks() {
    log::info("Noclip loaded");
}
