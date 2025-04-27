#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;

class $modify(JumpHackLayer, GJBaseGameLayer) {
public:
    void update(float dt) override {
        auto mod = Mod::get();
        bool jumpHackEnabled = mod->getSettingValue<bool>("enable-jump-hack");

        if (jumpHackEnabled && m_player1) {
            m_player1->m_isOnGround = true;
            m_player1->m_vehicleGrounded = true;
        }

        GJBaseGameLayer::update(dt);

        if (jumpHackEnabled && m_player1) {
            m_player1->m_isOnGround = true;
            m_player1->m_vehicleGrounded = true;
        }
    }

    static void onModify(auto& self) {
        auto hook = self.getHook("GJBaseGameLayer::update");
        Loader::get()->queueInMainThread([hook]() {
            hook->enable();
        });
    }
};
