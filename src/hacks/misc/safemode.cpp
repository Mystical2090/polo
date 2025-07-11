/* gtxripmxt i will add like some useless stuff includes because im bored
*/
#include <Geode/modify/GameStatsManager.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GameObject.hpp>
#include <Geode/modify/GJGameLevel.hpp>
#include <Geode/modify/FMODAudioEngine.hpp>
#include <Geode/modify/CCScheduler.hpp>
#include <Geode/modify/CCSprite.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/CCApplication.hpp>
#include <Geode/Geode.hpp>

extern bool safeModeEnabled;

using namespace geode::prelude;

class $modify(GJGameLevel) {
    void savePercentage(int p0, bool p1, int p2, int p3, bool p4) {
        if (!safeModeEnabled) {
            GJGameLevel::savePercentage(p0, p1, p2, p3, p4);
        }
    }
};
