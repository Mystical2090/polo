#include "speedhack.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

bool isSpeedhackBool() {
    return Mod::get()->getSettingValue<bool>("speedhack-bool");
}

float getSpeedhack() {
    return Mod::get()->getSettingValue<float>("speedhack");
}

float speedhackLogic(float dt) {
    if (isSpeedhackEnabled()) {
        float multiplier = getSpeedMultiplier();
        return std::clamp(dt * multiplier, 0.001f, 0.5f);
    }
    return dt;
}
