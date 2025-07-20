#include <Geode/Geode.hpp>
#include <Geode/modify/HardStreak.hpp>

using namespace geode::prelude;

extern bool noWavePulse;

$execute {
    geode::log::info("Wave pulse mod loaded");
}

class $modify(WavePulseMod, HardStreak) {
    void updateStroke(float p1) {
        if (noWavePulse) {
            m_pulseSize = 1.0f;
        } else {
            HardStreak::updateStroke(p1);
        }
    }
};
