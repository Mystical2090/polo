// qolmod go brrrrr anyways thanks doggo
#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
using namespace geode::prelude;

class $modify(JumpHack, GJBaseGameLayer) {
public:
    void update(float dt) override {
        auto mod = Mod::get();
        bool jumpHackEnabled = mod->getSettingValue<bool>("enable-jump-hack");
        
        if (jumpHackEnabled && m_player1) {
            m_player1->m_isOnGround = true;
        }
        
        GJBaseGameLayer::update(dt);
        
        if (jumpHackEnabled && m_player1) {
            m_player1->m_isOnGround = true;
        }
    }
    
    static void onModify(auto& self) {
        auto hook = self.getHook("GJBaseGameLayer::update");
        Loader::get()->queueInMainThread([hook]() {
            if (hook.isOk()) {
                hook.unwrap()->enable();
            }
        });
    }
};
