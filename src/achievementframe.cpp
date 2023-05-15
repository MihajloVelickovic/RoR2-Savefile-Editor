#include "achievementframe.h"
#include "achievementlist.h"
#include "mainframe.h"

AchievementFrame::AchievementFrame(MainFrame* parent, const wxString &title)
    :wxFrame(parent,
             wxID_ANY,
             title,
             wxDefaultPosition,
             wxSize(800,800),
             wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)){

        this->SetBackgroundColour(wxColor(33,33,33));

        auto panel = new wxScrolled<wxPanel>(this, wxID_ANY);
        auto sizer = new wxBoxSizer(wxVERTICAL);
        panel->SetScrollRate(0, FromDIP(10));

        wxStaticText* nameTextArray[118];
        wxStaticText* descTextArray[118];

        for(int i = ELITE_SLAYER; i<= SMUSHED; i++){

            nameTextArray[i] = new wxStaticText(panel,
                                                wxID_ANY,
                                                achievementList[i].GetName());

            bool color = false;
            for(int j=0;j<parent->GetAchievements().size();j++)
                if(parent->GetAchievements()[j] == achievementList[i].GetAchievement()){
                    nameTextArray[i]->SetForegroundColour(wxColor(46,232,71));
                    color = true;
                    break;
                }
            if(!color)
                nameTextArray[i]->SetForegroundColour(wxColor(188,50,50));

            nameTextArray[i]->SetFont(wxFont(12,
                                             wxFONTFAMILY_SWISS,
                                             wxFONTSTYLE_NORMAL,
                                             wxFONTWEIGHT_BOLD));

            descTextArray[i] = new wxStaticText(panel,
                                                wxID_ANY,
                                                _("-")+achievementList[i].GetDesc());
            descTextArray[i]->SetForegroundColour(nameTextArray[i]->GetForegroundColour());
            descTextArray[i]->SetFont(wxFont(10,
                                             wxFONTFAMILY_SWISS,
                                             wxFONTSTYLE_NORMAL,
                                             wxFONTWEIGHT_NORMAL));

            sizer->Add(nameTextArray[i], 0, wxALIGN_CENTER, FromDIP(10));
            sizer->Add(descTextArray[i], 0, wxALIGN_CENTER, FromDIP(10));
        }
        panel->SetSizer(sizer);
}
