#include <Geode/Geode.hpp>
#include <Geode/modify/GameStatsManager.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/FMODAudioEngine.hpp>

class $modify(GameStatsManager) {
    bool isItemUnlocked(UnlockType p0, int p1) {
        if (p0 != UnlockType::GJItem || p1 != 17) return GameStatsManager::isItemUnlocked(p0,p1);
        if (Mod::get()->getSettingValue<bool>("instant-respawn")) {
            return true;
        } else {
            return GameStatsManager::isItemUnlocked(p0,p1);
        }
    }
};
