#include <Geode/Geode.hpp>
#include <Geode/modify/GameStatsManager.hpp>

using namespace geode::prelude;

class $modify(GameStatsManager) {
    bool isItemUnlocked(UnlockType type, int itemID) {
        if (Mod::get()->getSettingValue<bool>("practice-music-hack")) {
            if (type == UnlockType::GJItem && itemID == 17) {
                return true;
            }
        }
        return GameStatsManager::isItemUnlocked(type, itemID);
    }
};
