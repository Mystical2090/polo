// i dont expect this to work im drunk rn
#include <Geode/Geode.hpp>
#include <Geode/modify/GameStatsManager.hpp>
#include <Geode/modify/GJGameLevel.hpp>

using namespace geode::prelude;

class $modify(SafeModeStatsBlocker, GameStatsManager) {
    void incrementStat(StatType type, int value) {
        if (Mod::get()->getSettingValue<bool>("safe-mode") && type == StatType::LevelComplete) {
            log::info("Safe Mode active: Blocking stat increment for LevelComplete.");
            return;
        }
        GameStatsManager::incrementStat(type, value);
    }
};

class $modify(SafeModeLevelBlocker, GJGameLevel) {
    void levelWasCompleted() {
        if (Mod::get()->getSettingValue<bool>("safe-mode")) {
            log::info("Safe Mode active: Blocking level completion for {}", this->m_levelName);

            this->m_normalPercent = 0;
            this->m_isVerified = false;
            this->m_isCompleted = false;

            return;
        }

        GJGameLevel::levelWasCompleted();
    }
};

