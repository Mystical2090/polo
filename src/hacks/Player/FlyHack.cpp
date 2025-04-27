#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(Jumphack, PlayerObject) {
public:
    void pushButton(PlayerButton btn) {
        if (Mod::get()->getSettingValue<bool>("enable-jump-hack")) {
            if (btn == PlayerButton::Jump) {
                this->jump(); // jump when on air or jot on ground hehdbds
                return;
            }
        }

        PlayerObject::pushButton(btn);
    }
};