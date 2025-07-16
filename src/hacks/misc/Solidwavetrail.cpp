#include <Geode/Geode.hpp>
#include <Geode/modify/CCDrawNode.hpp>
using namespace geode::prelude;

extern bool SolidWave;

class $modify (HelloMyNameIsGtxx, CCDrawNode) {
    bool drawPolygon(CCPoint *verts, unsigned int count, const ccColor4F &fillColor, float borderWidth, const ccColor4F &borderColor) {
        ccColor4F fill = fillColor;
        if (SolidWave) {
            fill = ccc4f(getColor().r / 255.0f, getColor().g / 255.0f, getColor().b / 255.0f, getOpacity() / 255.0f);
            setBlendFunc({GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA});
        }
        else {
            CCDrawNode::drawPolygon(verts, count, fill, borderWidth, borderColor);
        }
        return true;
    }
};
