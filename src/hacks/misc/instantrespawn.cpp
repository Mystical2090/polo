#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;

class $modify(GJBaseGameLayer) {
    struct Fields {
        bool fix = false;
    };

    void update(float dt) override {
        GJBaseGameLayer::update(dt);

        if (auto playLayer = as<PlayLayer*>(this)) {
            if (!m_fields->fix) {
                playLayer->playPlatformerEndAnimationToPos(ccp(2, 2), false);
                m_fields->fix = true;
            }
        }
    }
};
