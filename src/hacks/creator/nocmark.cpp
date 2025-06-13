#include <Geode/Geode.hpp>
#include <Geode/modify/EditLevelLayer.hpp> // since im bored im going to include some useless things
// nevermind
using namespace geode::prelude;

class $modify(EditLevelLayer) {
    void onShare(CCObject* sender) {
        if (Mod::get()->getSettingValue<bool>("noc")) {
            this->m_level->m_originalLevel = 0;
        }

        EditLevelLayer::onShare(sender);
    }
};
