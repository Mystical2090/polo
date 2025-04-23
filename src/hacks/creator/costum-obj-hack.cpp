#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>// idk this might be wrong im lazy to check

using namespace geode::prelude;

class $modify(EditorUI) {
    void onSaveCustomObject(CCObject* sender) {
        if (Mod::get()->getSettingValue<bool>("custom-obj-bypass")) {
            log::info("Bypassing custom object limit...");
            this->m_customObjectDict->setObject(CCArray::create(), CCDictionary::create()->count() + 1);
            EditorUI::onSaveCustomObject(sender);
            return;
        }
        EditorUI::onSaveCustomObject(sender);
    }
};