#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(PauseLayer) {
    void customSetup() override {
        auto a = PlayLayer::get()->m_level->m_levelType;

        if (Mod::get()->getSettingValue<bool>("level-edit")) {
            PlayLayer::get()->m_level->m_levelType = GJLevelType::Editor;
        }

        PauseLayer::customSetup();

        PlayLayer::get()->m_level->m_levelType = a;
    }

    void onEdit(cocos2d::CCObject* sender) {
        auto a = PlayLayer::get()->m_level->m_levelType;

        if (Mod::get()->getSettingValue<bool>("level-edit")) {
            PlayLayer::get()->m_level->m_levelType = GJLevelType::Editor;
        }

        PauseLayer::onEdit(sender);

        PlayLayer::get()->m_level->m_levelType = a;
    }
};
