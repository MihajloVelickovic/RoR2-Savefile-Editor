#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H
#include <wx/wx.h>
class Achievement{
private:
    wxString m_Name, m_Description, m_Unlock, m_Achievement;
public:
    Achievement(const wxString& name, const wxString& description, const wxString& achievement, const wxString& unlock);
    wxString GetName();
    wxString GetDesc();
    wxString GetUnlock();
    wxString GetAchievement();
    static bool AchievementExists(const wxString& achievementName);
};
#endif
