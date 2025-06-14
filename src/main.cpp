#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

void loadPlayerHacks();
void loadGlobalHacks();
void loadMiscHacks();
void loadEditorHacks();
void loadHacks();
void Hacks();

$on_mod(Loaded) {

}

class $modify(MyMenuLayer, MenuLayer) {
    void onMoreGames(CCObject* sender) {
        geode::createQuickPopup(
            "Polo",
            "Polo loaded!",
            "Yippie", "Noooo!",
            [](auto popup, bool btn2) {
                if (btn2) {
                    int* crash = nullptr;
                    *crash = 1337;
                } else {
                    geode::createQuickPopup(
                        "Thanks!",
                        "Thanks for supporting us!",
                        "Ok!, We will keep it up!", nullptr,
                        [](auto, bool) {
                        }
                    );
                }
            }
        );
    }
};
