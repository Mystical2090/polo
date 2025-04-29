#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;

class $modify(AutoClickLayer, PlayLayer) {
    void update(float dt) {
        if (Mod::get()->getSettingValue<bool>("enable-auto-click"))
            if (this->m_player1) this->pushButton(0, true);
        PlayLayer::update(dt);
    }
};
