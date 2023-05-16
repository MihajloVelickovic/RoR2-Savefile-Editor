#ifndef CLICKABLE_TEXT_H
#define CLICKABLE_TEXT_H
#include <wx/wx.h>
class ClickableText: public wxStaticText{
private:
    wxStaticText* m_Subtext;
public:
    ClickableText(wxWindow* parent, wxWindowID id, const wxString& label, wxStaticText* subtext);
    void OnTextClick(wxMouseEvent& evt);
};
#endif
