#include <Geode/Geode.hpp>
#include <Geode/modify/GameManager.hpp>
using namespace geode::prelude;

extern bool colorHackEnabled;

class $modify(MyMenuLayer, GameManager) {
    bool isIconUnlocked(int p0, IconType p1) {
        bool result = GameManager::isIconUnlocked(p0, p1);
        if (colorHackEnabled) {
            return true;
        }
        return result;
    }
};
