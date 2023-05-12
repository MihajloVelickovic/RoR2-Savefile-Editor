#ifndef FRAME_H
#define FRAME_H
#include <wx/wx.h>
class Frame: public wxFrame{
private:
    wxString m_Value;
    wxTextCtrl* m_TextBox;
public:
    explicit Frame(const wxString& title);
    void OnButtonClicked(wxCommandEvent& evt);
};
#endif
