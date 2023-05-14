#ifndef ACHIEVEMENTFRAME_H
#define ACHIEVEMENTFRAME_H
#include <wx/wx.h>
#include "mainframe.h"
class AchievementFrame: public wxFrame {
public:
    AchievementFrame(MainFrame* parent, const wxString& title);
    void OnCheckBoxClick(wxCommandEvent& evt);
};


#endif
