#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(PauseLayer) {
    void customSetup() {
        if (!Mod::get()->getSavedValue<bool>("hide-pause-menu")) {
            PauseLayer::customSetup();
        }
    }
};

$execute {
    Loader::get()->queueInMainThread([] {
        if (auto mod = Mod::get()) {
            mod->onSettingChanged("hide-pause-menu", [](bool enabled) {
                if (auto scene = CCDirector::get()->getRunningScene()) {
                    if (auto p = typeinfo_cast<PauseLayer*>(scene->getChildByType<PauseLayer>(0))) {
                        p->setVisible(!enabled);
                    }
                }
            });
        }
    });
}
