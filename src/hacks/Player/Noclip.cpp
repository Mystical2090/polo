#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(NoclipPlayer, PlayerObject) {
    auto value = Mod::get()->getSettingValue<bool>("bool-setting-example");
    void pushButton(PlayerButton btn) {
        if (Mod::get()->getSettingValue<bool>("noclip")) {
            this->m_isDead = false; // The actual mod
            this->m_yVelocity = std::max(this->m_yVelocity, static_cast<decltype(this->m_yVelocity)>(-5.0));
        }

        PlayerObject::pushButton(btn); // Calles the method
    }
};
