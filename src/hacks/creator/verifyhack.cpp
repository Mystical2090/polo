#include <Geode/Geode.hpp>
#include <Geode/modify/EditLevelLayer.hpp>

using namespace geode::prelude;

extern bool verifyHackEnabled;

class $modify(VerifyHackHmmm, EditLevelLayer) {
    bool init(GJGameLevel* gl) {
        if (verifyHackEnabled) {
            gl->m_isVerified = true;
        }
        return EditLevelLayer::init(gl);
    }
}; // working
