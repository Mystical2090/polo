#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(PlayerObject) {
    void handleButton(bool down, int button, bool player1) {
        if (!Mod::get()->getSettingValue<bool>("ignore-inputs")) {
            PlayerObject::handleButton(down, button, player1);
        }
// here do nothing yes hmmm
    }
};
