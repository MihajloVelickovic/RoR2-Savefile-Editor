#include "clickabletext.h"
#include "achievementlist.h"
ClickableText::ClickableText(wxWindow *parent, wxWindowID id, const wxString &label,  wxStaticText* subtext)
    :wxStaticText(parent, id, label), m_Subtext(subtext){
        Bind(wxEVT_LEFT_DOWN, &ClickableText::OnTextClick, this);
}

void ClickableText::OnTextClick(wxMouseEvent &evt) {
    wxColor current = GetForegroundColour();
    SetForegroundColour(current == UNLOCKED
                        ?LOCKED:UNLOCKED);
    m_Subtext->SetForegroundColour(current==UNLOCKED
                                   ?LOCKED:UNLOCKED);
}

