#include <Geode/Geode.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>

using namespace geode::prelude;

class $modify(VerifyHackHmmm, EditLevelLayer) {
        bool init(GJGameLevel* gl) {
            gl->m_isVerified = true;
            return EditLevelLayer::init(gl);
        }
    };
