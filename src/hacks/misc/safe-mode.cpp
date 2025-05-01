#include <Geode/Geode.hpp>
#include <Geode/modify/GameStatsManager.hpp>
#include <Geode/modify/GJGameLevel.hpp>

using namespace geode::prelude;

class $modify(SafeMode, GameStatsManager) {
    void incrementStat(StatType type, int value) {
        if (Mod::get()->getSettingValue<bool>("safe-mode") && type == StatType::LevelComplete) {
            log::info("Safe Mode: blocking level completion increment.");
            return; // Block the stat increment when in Safe Mode
        }

        GameStatsManager::incrementStat(type, value);
    }
};

class $modify(SafeMode, GJGameLevel) {
    void levelWasCompleted() {
        if (Mod::get()->getSettingValue<bool>("safe-mode")) {
            log::info("Safe Mode active — level completion blocked.");

            // Prevent completion and stats updates
            this->m_normalPercent = 0;
            this->m_isVerified = false;
            this->m_isCompleted = false;

            // ssds
            return; // Prevent completion logic
        }

        GJGameLevel::levelWasCompleted(); // Allow normal completion logic
    }
};
