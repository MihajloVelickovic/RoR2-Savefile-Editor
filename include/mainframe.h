#ifndef FRAME_H
#define FRAME_H
#include <wx/wx.h>
#include <vector>
class MainFrame: public wxFrame{
private:
    wxString m_Value, m_Path;
    std::vector<wxString> m_Achievements;
    wxTextCtrl* m_TextBox;
    wxButton* m_AchievementButton;
public:
    explicit MainFrame(const wxString& title);
    void OnLoadButtonClicked(wxCommandEvent& evt);
    void OnSaveButtonClicked(wxCommandEvent& evt);
    void OnAchievementButtonClicked(wxCommandEvent& evt);
    std::vector<wxString> GetAchievements();
};
#endif
