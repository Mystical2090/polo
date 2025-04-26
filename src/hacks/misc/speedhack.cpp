#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;

class $modify(Speedhack, GJBaseGameLayer) {
public:
    void update(float dt) { // delta time is bad
        if (Mod::get()->getSettingValue<bool>("speedhack-bool")) {
            float multiplier = Mod::get()->getSettingValue<float>("speedhack");
            GJBaseGameLayer::update(dt * multiplier);
        } else {
            GJBaseGameLayer::update(dt);
        }
    }
};   // dinno if itll work or not but migjt eork dhdnn