/* gtxripmxt i will add like some useless stuff includes because im bored
*/
#include <Geode/modify/GameStatsManager.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GameObject.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/GJGameLevel.hpp>
#include <Geode/modify/FMODAudioEngine.hpp>
#include <Geode/modify/CCScheduler.hpp>
#include <Geode/modify/CCSprite.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/CCApplication.hpp>
#include <Geode/Geode.hpp>

using namespace geode::prelude;

extern bool everythingKillsYouEnabled;
extern bool noSolidsEnabled;

class $modify(dick, PlayerObject) {
    void collidedWithObject(float p0, GameObject* obj, cocos2d::CCRect p2, bool p3) {
        if (everythingKillsYouEnabled) {
            if (auto playLayer = PlayLayer::get()) {
                playLayer->destroyPlayer(this, obj);
            }
        }

        if (!noSolidsEnabled) {
            PlayerObject::collidedWithObject(p0, obj, p2, p3);
        }
    }
};
