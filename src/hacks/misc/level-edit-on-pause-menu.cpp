#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

extern bool levelEditEnabled;

class $modify(PauseLayer) {
    void customSetup() override {
        PauseLayer::customSetup();

        auto a = PlayLayer::get()->m_level->m_levelType;

        if (levelEditEnabled) {
            PlayLayer::get()->m_level->m_levelType = GJLevelType::Editor;
        }

        PlayLayer::get()->m_level->m_levelType = a;
    }

    void onEdit(cocos2d::CCObject* sender) {
        auto a = PlayLayer::get()->m_level->m_levelType;

        if (levelEditEnabled) {
            PlayLayer::get()->m_level->m_levelType = GJLevelType::Editor;
        }

        PauseLayer::onEdit(sender);

        PlayLayer::get()->m_level->m_levelType = a;
    }
};
