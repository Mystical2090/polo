#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(NoclipHack, PlayLayer) {
    void update(float dt) {
        if (Mod::get()->getSettingValue<bool>("enable-noclip")) {
            if (this->m_player1 && this->m_player1->m_isDead) {
    this->m_player1->m_isDead = false;
    this->m_player1->m_hasJustDied = false;
    this->m_player1->m_objectType = GameObjectType::Player;
}
        }
        PlayLayer::update(dt);
    }
};
