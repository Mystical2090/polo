#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

void loadPlayerHacks();
void loadGlobalHacks();
void loadMiscHacks();
void loadEditorHacks();
void loadHacks();
void Hacks();
// the above functions are useless 
$on_mod(Loaded) {

}

class $modify(pololayer, MenuLayer) {
    void onMoreGames(CCObject* sender) {
        geode::createQuickPopup(
            "Polo",
            "Polo loaded!",
            "Yippie", "Noooo!",
            [](auto popup, bool btn2) {
                if (btn2) {
                    FLAlertLayer::create (
                    "Ok but im sad...",
                    "Next time can you click yippie?",
                    "Ok i will!"
                )->show();

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
