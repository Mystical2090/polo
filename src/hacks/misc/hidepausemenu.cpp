#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();

        if (Mod::get()->getSavedValue<bool>("hide-pause-menu")) {
            this->setVisible(false);
        }
    }
};
