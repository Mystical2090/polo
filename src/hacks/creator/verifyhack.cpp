#include <Geode/Geode.hpp>
#include <Geode/modify/EditLevelLayer.hpp>

using namespace geode::prelude;

class $modify(VerifyHackHmmm, EditLevelLayer) {
    bool init(GJGameLevel* gl) {
        if (Mod::get()->getSettingValue<bool>("verify-hack")) {
            gl->m_isVerified = true;
        }
        return EditLevelLayer::init(gl);
    }
}; // working
