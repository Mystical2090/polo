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
            // Remove m_vehicleGrounded as it doesn't exist in PlayerObject
        }
        
        GJBaseGameLayer::update(dt);
        
        if (jumpHackEnabled && m_player1) {
            m_player1->m_isOnGround = true;
            // Remove m_vehicleGrounded as it doesn't exist in PlayerObject
        }
    }
    
    static void onModify(auto& self) {
        auto hook = self.getHook("GJBaseGameLayer::update");
        Loader::get()->queueInMainThread([hook]() {
            // Use unwrap() to get the pointer from Result<Hook*>
            if (hook.isOk()) {
                hook.unwrap()->enable();
            }
        });
    }
};
