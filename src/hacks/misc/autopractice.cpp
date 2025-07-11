// if this doesn't work I'm using ai
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

extern bool autoPracticeEnabled;

using namespace geode::prelude;
class $modify(PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects))
            return false;

        if (autoPracticeEnabled) {
            this->togglePracticeMode(true);
        }

        return true;
    }
};
