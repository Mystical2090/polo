#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

extern bool noclipEnabled;

class $modify(PlayLayer) {
    void destroyPlayer(PlayerObject* p0, GameObject* p1) {
        if (p1 == m_anticheatSpike) {
            return PlayLayer::destroyPlayer(p0, p1);
        }

        if (!noclipEnabled) {
            PlayLayer::destroyPlayer(p0, p1);
        }
    }
};
