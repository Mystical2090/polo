#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <cocos2d.h>

using namespace geode::prelude;

class $modify(SpeedHack, PlayLayer) {
    void update(float dt) {
        float speed = Mod::get()->getSettingValue<double>("speed-value");
        speed = std::clamp(speed, 0.1f, 5.0f); //fixxy fix
        PlayLayer::update(dt * speed);
    }
};
