#include <Geode/Geode.hpp>
#include <Geode/modify/GameManager.hpp> // balls
using namespace geode::prelude;

class $modify(Speedhack, GameManager) {
    void setGameSpeed(float speed) {
        if (Mod::get()->getSettingValue<bool>("speedhack-bool")) {
            float multiplier = Mod::get()->getSettingValue<float>("speedhack");
            setGameSpeed$base(speed * multiplier);
        } else {
            setGameSpeed$base(speed);
        }
    }
};
