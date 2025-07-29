#include <Geode/Geode.hpp>
#include "src/ui.hpp"
#include <Geode/modify/PlayerObject.hpp>
using namespace geode::prelude;
class $modify(PlayerObject) {
    bool pushButton(PlayerButton button) {
        if (!ignoreInputsEnabled()) {
            return PlayerObject::pushButton(button);
        }
        return true;
    }
    
    bool releaseButton(PlayerButton button) {
        if (!ignoreInputsEnabled()) {
            return PlayerObject::releaseButton(button);
        }
        return true;
    }
};
