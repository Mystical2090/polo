#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(JumpHackPlayer, PlayerObject) {
public:
    void pushButton(PlayerButton btn) {
        if (Mod::get()->getSettingValue<bool>("enable-jump-hack")) {
            if (btn == PlayerButton::Jump) {
                this->m_isOnGround = true; // Fake i sh*t my pants
            }
        }

        PlayerObject::pushButton(btn);
    }
};