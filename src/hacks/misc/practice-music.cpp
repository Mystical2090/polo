#include <Geode/Geode.hpp>
#include <Geode/modify/GameStatsManager.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/FMODAudioEngine.hpp>

class $modify(GameStatsManager) {
    bool isItemUnlocked(UnlockType p0, int p1) {
        // did i seriously not see this, all i changed was && to || hA!
        if (p0 != UnlockType::GJItem || p1 != 17) return GameStatsManager::isItemUnlocked(p0,p1);
        if (Hacks::isHackEnabled("Practice Music") && p1 == 17) {
            return true;
        } else {
            return GameStatsManager::isItemUnlocked(p0,p1);
        }
    }
