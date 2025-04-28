#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
using namespace geode::prelude;

class $modify(PlayerObject) {
    bool pushButton(PlayerButton button) {
        if (!Mod::get()->getSettingValue<bool>("ignore-inputs")) {
            return PlayerObject::pushButton(button);
        }
        return true;
    }
    
    bool releaseButton(PlayerButton button) {
        if (!Mod::get()->getSettingValue<bool>("ignore-inputs")) {
            return PlayerObject::releaseButton(button);
        }
        return true;
    }
};
