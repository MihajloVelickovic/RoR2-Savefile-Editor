#ifndef FRAME_H
#define FRAME_H
#include <wx/wx.h>
class MainFrame: public wxFrame{
private:
    wxString m_Value, m_Path;
    wxTextCtrl* m_TextBox;
public:
    explicit MainFrame(const wxString& title);
    void OnLoadButtonClicked(wxCommandEvent& evt);
    void OnSaveButtonClicked(wxCommandEvent& evt);
};
#endif
