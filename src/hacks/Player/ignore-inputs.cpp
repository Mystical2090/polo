#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(PlayerObject) {
    void handleButton(bool down, int button, bool player1) {
         if (Mod::get()->getSettingValue<bool>("ignore-inputs")) {
                return;
            GJBaseGameLayer::handleButton(down, button, player1);
    } else {
                return;
}