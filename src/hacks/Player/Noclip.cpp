#include <Geode/Geode.hpp>
#include "src/ui.hpp"
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;

class $modify(Noclip, PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* object) {
        if (!noclipEnabled()) {
            PlayLayer::destroyPlayer(player, object);
        }
    }
};
