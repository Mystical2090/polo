#include <Geode/Geode.hpp>
#include <Geode/modify/GameManager.hpp>

using namespace geode::prelude;

class $modify(Speedhack, GameManager) {
    void setGameSpeed(float speed) {
        if (Mod::get()->getSettingValue<bool>("speedhack-bool")) {
            float multiplier = Mod::get()->getSettingValue<float>("speedhack");
            GameManager::setGameSpeed(speed * multiplier);
        } else {
            GameManager::setGameSpeed(speed);
        }
    }
};