#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <cocos2d.h>

using namespace geode::prelude;

class $modify(SpeedHack, PlayLayer) {
    void update(float dt) {
        if (Mod::get()->getSettingValue<bool>("speedhack-bool")) {
            float speed = Mod::get()->getSettingValue<double>("speed-value");
            speed = std::clamp(speed, 0.01f, 5.0f);
            PlayLayer::update(dt * speed);
        } else {
            PlayLayer::update(dt);
        }
    }
};
