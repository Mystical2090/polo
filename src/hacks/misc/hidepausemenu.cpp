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
    static bool lastState = Mod::get()->getSavedValue<bool>("hide-pause-menu");

    CCDirector::get()->getScheduler()->schedule([](float) {
        bool current = Mod::get()->getSavedValue<bool>("hide-pause-menu");
        if (current != lastState) {
            lastState = current;

            if (auto scene = CCDirector::get()->getRunningScene()) {
                if (auto pause = typeinfo_cast<PauseLayer*>(scene->getChildByType<PauseLayer>(0))) {
                    pause->setVisible(!current);
                }
            }
        }
    }, CCDirector::get(), 0.1f, false, "hide-pause-toggle-watcher");
}
