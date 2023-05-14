#include "achievement.h"
#include "achievementlist.h"

Achievement::Achievement(const wxString& name,
                         const wxString& description,
                         const wxString& achievement,
                         const wxString& unlock)
         :m_Name(name), m_Description(description), m_Achievement(achievement), m_Unlock(unlock){}

wxString Achievement::GetName() {
    return m_Name;
}

wxString Achievement::GetDesc() {
    return m_Description;
}

wxString Achievement::GetUnlock() {
    return m_Unlock;
}

wxString Achievement::GetAchievement() {
    return m_Achievement;
}

bool Achievement::AchievementExists(const wxString &achievementName) {
    for(int i=ELITE_SLAYER; i<=SMUSHED; i++)
        if(achievementList[i].GetAchievement() == achievementName)
            return true;
    return false;
}


