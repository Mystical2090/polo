#include <Geode/Geode.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
#include <Geode/modify/UploadActionPopup.hpp>

using namespace geode::prelude;

class $modify(UploadActionPopup) {
    bool init(UploadPopupDelegate* delegate, gd::string str) {
        if (Mod::get()->getSettingValue<bool>("verify-hack")) {
            auto level = GameLevelManager::sharedState()->getMainLevel(); // Adjust this to your needs
            level->m_isVerified = true;
        }
        return UploadActionPopup::init(delegate, str);
    }
};

class $modify(LevelEditorLayer) {
    void onSaveLevel() {
        if (Mod::get()->getSettingValue<bool>("verify-hack")) {
            m_level->m_isVerified = true;
        }
        base::onSaveLevel(); // this should fix it i hope
    }
};
