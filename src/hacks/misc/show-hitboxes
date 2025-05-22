#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
    static void onModify(auto& self) {
        (void)self.setHookPriority("PlayLayer::updateVisibility", -6969);
    }

    void updateVisibility(float p0) {
        PlayLayer::updateVisibility(p0);

        if (!m_debugDrawNode)
            return;

        bool showAlways = Mod::get()->getSettingValue<bool>("show-hitboxes");
        bool showOnDeath = Mod::get()->getSettingValue<bool>("show-hitboxes-on-death");

        bool shouldVis =
            (GameManager::sharedState()->getGameVariable("0166") && m_isPracticeMode) ||
            showAlways ||
            (showOnDeath && m_player1->m_isDead);

        if (shouldVis)
            this->updateDebugDraw();

        m_debugDrawNode->setVisible(shouldVis);
    }

    void destroyPlayer(PlayerObject* player, GameObject* cause) {
        PlayLayer::destroyPlayer(player, cause);

        if (Mod::get()->getSettingValue<bool>("show-hitboxes-on-death")) {
            this->updateVisibility(0.f); // force refresh visibility logic
        }
    }
};
