#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(PlayerObject) {
    void pushButton(PlayerButton button) {
        if (Mod::get()->getSettingValue<bool>("ignore-inputs")) {
            return;
        }
        PlayerObject::pushButton(button);
    }

    void releaseButton(PlayerButton button) {
        if (Mod::get()->getSettingValue<bool>("ignore-inputs")) 
            return;
        }
        PlayerObject::releaseButton(button);
    }
};
