#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

extern bool customObjectsBypassEnabled;

class $modify(CustumObjectBypass, EditorUI) {
    void onNewCustomItem(CCObject* pSender) {
        if (!customObjectsBypassEnabled)) return EditorUI::onNewCustomItem(pSender);
        if (m_selectedObjects && m_selectedObjects->count() > 0) {
            if (auto gameManager = GameManager::sharedState()) {
                CCArray* objectsToCopy = m_selectedObjects->count() == 0 
                    ? CCArray::createWithObject(m_selectedObject)
                    : m_selectedObjects;
                gameManager->addNewCustomObject(copyObjects(objectsToCopy, false, false));
                m_selectedObjectIndex = 0;
                reloadCustomItems();
            }
        } else {
            EditorUI::onNewCustomItem(pSender);
        };
    };
};
