#include <Geode/Geode.hpp>
#include <Geode/modify/GameManager.hpp>

using namespace geode::prelude;

class $modify(Speedhack, GameManager) {
    void setGameSpeed(float speed) {
        if (Mod::get()->getSettingValue<bool>("speedhack-bool")) {
            float multiplier = Mod::get()->getSettingValue<float>("speedhack");
            Speedhack::setGameSpeed$base(speed * multiplier);
        } else {
            Speedhack::setGameSpeed$base(speed); // i like my cheese drippy bruh
        }
    }
};
