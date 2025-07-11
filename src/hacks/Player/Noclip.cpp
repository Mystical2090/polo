#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

extern bool noclipEnabled;

class $modify(Noclip, PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* object) {
        if (!noclipEnabled) {
            PlayLayer::destroyPlayer(player, object);
        }
    }
};
