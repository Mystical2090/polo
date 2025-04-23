#include <Geode/Geode.hpp>
#include <Geode/modify/GameStatsManager.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GameObject.hpp>
#include <Geode/modify/GJGameLevel.hpp>
using namespace geode::prelude;

class $modify(GJGameLevel) {
    void savePercentage(int p0, bool p1, int p2, int p3, bool p4) {
        if (Mod::get()->getSettingValue<bool>("verify-hack")) {
            gl->m_isVerified = true;
        }
            GJGameLevel::savePercentage(p0, p1, p2, p3, p4);
        
    }
};
