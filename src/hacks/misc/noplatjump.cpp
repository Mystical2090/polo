#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(PlayerObject) {
    void animatePlatformerJump(float p0) {
        if (Mod::get()->getSavedValue<bool>("disable-platformer-jump-anim")) {
            return;
        }

        PlayerObject::animatePlatformerJump(p0);
    }
};
