#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/utils/cocos.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects))
            return false;

        float speed = Mod::get()->getSettingValue<float>("speed-hack");
        CCDirector::get()->getScheduler()->setTimeScale(speed);

        return true;
    }

    void onExit() {
        CCDirector::get()->getScheduler()->setTimeScale(1.0f);
        PlayLayer::onExit();
    }
}; // ok 
