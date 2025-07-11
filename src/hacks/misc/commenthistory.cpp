#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>

using namespace geode::prelude;

extern bool commentHistoryBypassEnabled;

class $modify(ProfilePage) {
public:
    void loadPageFromUserInfo(GJUserScore* p0) {
        if (commentHistoryBypassEnabled) {
            auto state = p0->m_commentHistoryStatus;
            p0->m_commentHistoryStatus = 0;

            ProfilePage::loadPageFromUserInfo(p0);

            p0->m_commentHistoryStatus = state;
        }
        else {
            ProfilePage::loadPageFromUserInfo(p0);
        }
    }
};
