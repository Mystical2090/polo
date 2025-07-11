#include <Geode/Geode.hpp>
#include <Geode/modify/GameStatsManager.hpp>

using namespace geode::prelude;

extern bool practiceMusicHackEnabled;

class $modify(GameStatsManager) {
    bool isItemUnlocked(UnlockType type, int itemID) {
        if (practiceMusicHackEnabled) {
            if (type == UnlockType::GJItem && itemID == 17) {
                return true;
            }
        }
        return GameStatsManager::isItemUnlocked(type, itemID);
    }
};
