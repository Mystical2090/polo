#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
using namespace geode::prelude;

extern bool levelEditEnabled;

class $modify(PauseLayer) {
    void customSetup() override {
        PauseLayer::customSetup();
        
        auto originalLevelType = PlayLayer::get()->m_level->m_levelType;
        
        if (levelEditEnabled) {
            PlayLayer::get()->m_level->m_levelType = GJLevelType::Editor;
        }
    }
};
