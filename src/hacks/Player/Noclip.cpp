#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(NoclipPlayer, PlayerObject) {
    void pushButton(PlayerButton btn) {
        if (Mod::get()->getSettingValue<bool>("noclip")) {
            this->m_isDead = false; // Prevents dying
            this->m_yVelocity = std::max(this->m_yVelocity, -5.0f); // Avoid bugged falling
        }

        PlayerObject::pushButton(btn); // Call the original method
    }
}
