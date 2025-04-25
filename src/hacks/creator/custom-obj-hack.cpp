#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

class $modify(CostumObjectBypass, EditorUI) {
    void onNewCustomItem(CCObject* pSender) {
        if (!Mod::get()->getSettingValue<bool>("costum-obj-bypass")) return EditorUI::onNewCustomItem(pSender);
        if (m_selectedObjects && m_selectedObjects->count() > 0) {
            if (auto gameManager = GameManager::sharedState()) {
                CCArray* newSelectedObjs;
                if (m_selectedObjects->count() == 0) {
                    newSelectedObjs = cocos2d::CCArray::create();
                    newSelectedObjs->addObject(m_selectedObject);
                } else {
                    newSelectedObjs = this->m_selectedObjects;
                }
                gameManager->addNewCustomObject(copyObjects(newSelectedObjs, false, false));
                m_selectedObjectIndex = 0;
                reloadCustomItems();
            }
        } else {
            EditorUI::onNewCustomItem(pSender);
        }