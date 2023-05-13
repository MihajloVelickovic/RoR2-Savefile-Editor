#include "achievementframe.h"

AchievementFrame::AchievementFrame(wxFrame* parent, const wxString &title)
    :wxFrame(parent,
             wxID_ANY,
             title,
             wxDefaultPosition,
             wxSize(400,800),
             wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)){

        this->SetBackgroundColour(wxColor(33,33,33));
}
