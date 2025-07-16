#include <Geode/Geode.hpp>
#include <Geode/modify/HardStreak.hpp>
using namespace geode::prelude;

extern bool noWavePulse

class $modify (Hi, HardStreak) {
    void updateStroke(float p1) {
        if (noWavePulse) {
            m_pulseSize = 1;
        } 
        else {
            HardStreak::updateStroke(p1);
        }
    }
};
