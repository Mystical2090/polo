#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

extern bool autoPracticeEnabled;

using namespace geode::prelude;
class $modify(Hey, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (autoPracticeEnabled) {
            this->togglePracticeMode(true);
        }
        return true;
    }
};
