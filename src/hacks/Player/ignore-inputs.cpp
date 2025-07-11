#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
using namespace geode::prelude;

extern bool ignoreInputsEnabled;

class $modify(PlayerObject) {
    bool pushButton(PlayerButton button) {
        if (!ignoreInputsEnabled) {
            return PlayerObject::pushButton(button);
        }
        return true;
    }
    
    bool releaseButton(PlayerButton button) {
        if (!ignoreInputsEnabled) {
            return PlayerObject::releaseButton(button);
        }
        return true;
    }
};
