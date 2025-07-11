#include <Geode/Geode.hpp>
#include <Geode/modify/GameManager.hpp>

using namespace geode::prelude;

extern bool colorHackEnabled;

class $modify(Layer, GameManager) {
bool isColorUnlocked(int p0, UnlockType p1) {
         bool result = GameManager::isColorUnlocked(p0, p1);
 
         if (colorHackEnabled) {
             return true;
         }
 
         return result;
     }
 };
