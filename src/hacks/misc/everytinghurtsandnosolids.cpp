#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
using namespace geode::prelude;

extern bool everythingKillsYouEnabled;

class $modify(MyPlayerObject, PlayerObject) {
    void collidedWithObject(float p0, GameObject* obj, cocos2d::CCRect p2, bool p3) {
        if (everythingKillsYouEnabled) {
            if (auto playLayer = PlayLayer::get()) {
                playLayer->destroyPlayer(this, obj);
            }
        }
        else {
            PlayerObject::collidedWithObject(p0, obj, p2, p3);
        }
    }
};
