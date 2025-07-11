#include <Geode/modify/HardStreak.hpp>
using namespace geode::prelude;

extern bool noWavePulse

class $modify (HardStreak)
{
    void updateStroke(float unused)
    {
        if (noWavePulse)
            m_pulseSize = 1;
        HardStreak::updateStroke(unused);
    }
};
