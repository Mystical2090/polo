#include <Geode/Geode.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
#include <Geode/modify/UploadActionPopup.hpp>

using namespace geode::prelude;

class $modify(UploadActionPopup) {
    bool init(GJGameLevel* level) {
        if (Mod::get()->getSettingValue<bool>("verify-hack")) {
            level->m_isVerified = true;
        }
        return UploadActionPopup::init(level);
    }
};

class $modify(LevelEditorLayer) {
    void onSaveLevel() {
        if (Mod::get()->getSettingValue<bool>("verify-hack")) {
            m_level->m_isVerified = true;
        }
        LevelEditorLayer::onSaveLevel();
    }
};
