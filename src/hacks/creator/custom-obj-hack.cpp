#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

class $modify(customobjbypassthing, EditorUI) {

    void onNewCustomItem(CCObject* sender) {
            if (auto gameManager = utils::get<GameManager>()) {
                cocos2d::CCArray* newSelectedObjs;
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
        }
    };
}
