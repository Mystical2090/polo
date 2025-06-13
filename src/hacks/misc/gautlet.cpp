#include <Geode/Geode.hpp>
#include <Geode/modify/GauntletLayer.hpp>

using namespace geode::prelude;

class $modify(GauntletLayer) {
    void loadLevelsFinished(cocos2d::CCArray* p0, const char* p1, int p2) {
        GauntletLayer::loadLevelsFinished(p0, p1, p2);

        auto setting = Mod::get()->getSetting("gautlet");
        auto boolSetting = std::dynamic_pointer_cast<geode::SettingBool>(setting);
        if (!boolSetting || !boolSetting->value()) {
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

    bool init(GauntletType p0) {
        if (!GauntletLayer::init(p0)) {
            return false;
        }

        auto setting = Mod::get()->getSetting("gautlet");
        auto boolSetting = std::dynamic_pointer_cast<geode::SettingBool>(setting);
        if (!boolSetting || !boolSetting->value()) {
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
