#include <Geode/Geode.hpp>
#include <Geode/modify/GauntletLayer.hpp>

using namespace geode::prelude;

class $modify(GauntletLayer) {
    void loadLevelsFinished(cocos2d::CCArray* p0, const char* p1, int p2) override {
        GauntletLayer::loadLevelsFinished(p0, p1, p2);

        if (!Mod::get()->getSetting<bool>("gautlet")) {
            return;
        }

        if (auto menu = getChildByIDRecursive("levels-menu")) {
            for (auto child : CCArrayExt<CCNode*>(menu->getChildren())) {
                if (auto btn = typeinfo_cast<CCMenuItem*>(child)) {
                    btn->setEnabled(true);
                }
            }
        }
    }

    bool init(GauntletType p0) override {
        if (!GauntletLayer::init(p0)) {
            return false;
        }

        if (!Mod::get()->getSetting<bool>("gautlet")) {
            return true;
        }

        if (auto menu = getChildByIDRecursive("levels-menu")) {
            for (auto child : CCArrayExt<CCNode*>(menu->getChildren())) {
                if (auto btn = typeinfo_cast<CCMenuItem*>(child)) {
                    btn->setEnabled(true);
                }
            }
        }

        return true;
    }
};
