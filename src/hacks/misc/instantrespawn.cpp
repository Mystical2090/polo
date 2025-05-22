#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;

class $modify(GJBaseGameLayer) {
    struct Fields {
        bool hasCompleted = false;
    };

    void update(float dt) override {
        GJBaseGameLayer::update(dt);
        
        if (!Mod::get()->getSettingValue<bool>("instant-complete"))
            return;

        if (auto playLayer = typeinfo_cast<PlayLayer*>(this)) {
            if (!m_fields->hasCompleted) {
                playLayer->playPlatformerEndAnimationToPos({2.f, 2.f}, false);
                m_fields->hasCompleted = true;
            }
        }
    }
};
