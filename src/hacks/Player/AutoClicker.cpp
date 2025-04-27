#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;

class $modify(AutoClikcer, GJBaseGameLayer) {
public:
    struct Fields {
        int frames = 0;
        int framesHeld = 0;
        bool isHeld = false;
    };

    void checkRepellPlayer() override {
        GJBaseGameLayer::checkRepellPlayer();

        auto& fcont = m_fields.self();

        fcont->frames++;

        auto mod = Mod::get();
        int delay = mod->getSettingValue<int>("auto-clicker-delay");
        int holdFor = mod->getSettingValue<int>("auto-clicker-holdfor");
        bool player1Enabled = mod->getSettingValue<bool>("auto-clicker-player1");
        bool player2Enabled = mod->getSettingValue<bool>("auto-clicker-player2");

        if (fcont->frames >= delay) {
            fcont->frames = 0;
            fcont->framesHeld = 0;
        }

        if (fcont->frames == 0) {
            if (player1Enabled)
                this->handleButton(true, static_cast<int>(PlayerButton::Jump), true);

            if (player2Enabled && m_player2 && m_gameState.m_isDualMode)
                this->handleButton(true, static_cast<int>(PlayerButton::Jump), false);

            fcont->isHeld = true;
        }

        if (fcont->framesHeld >= holdFor) {
            if (player1Enabled)
                this->handleButton(false, static_cast<int>(PlayerButton::Jump), true);

            if (player2Enabled && m_player2 && m_gameState.m_isDualMode)
                this->handleButton(false, static_cast<int>(PlayerButton::Jump), false);

            fcont->isHeld = false;
        }

        if (fcont->isHeld)
            fcont->framesHeld++;
    }

    static void onModify(auto& self) {
        auto hook = self.getHook("GJBaseGameLayer::checkRepellPlayer");
        Loader::get()->queueInMainThread([hook]() {
            hook->enable();
        });
    }
};
