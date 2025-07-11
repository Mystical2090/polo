#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;

extern float speedhackValue;

class $modify(Speedhack, GJBaseGameLayer) {
public:
    void update(float dt) {
        if (speedhackValue != 1.0f) {
            GJBaseGameLayer::update(dt * speedhackValue);
        } else {
            GJBaseGameLayer::update(dt);
        }
    }
};
