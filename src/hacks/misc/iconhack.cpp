#include <Geode/Geode.hpp>
#include <Geode/modify/GameManager.hpp>
using namespace geode::prelude;

extern bool iconHackEnabled;

class $modify(MyMenuLayer, GameManager) {
    bool isIconUnlocked(int p0, IconType p1) {
        if (iconHackEnabled) {
            return true;
        }
        else {
            GameManager::isIconUnlocked(p0, p1);
        }
    }
};
