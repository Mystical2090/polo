#include <Geode/Geode.hpp>
#include <Geode/modify/HardStreak.hpp>
using namespace geode::prelude;

extern float noWavePulseValue;

class $modify(HardStreak) {
    void updateStroke(float p0) {
        m_pulseSize = noWavePulseValue + 0.5f;
        HardStreak::updateStroke(p0);
    }
};
