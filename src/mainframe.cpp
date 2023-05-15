#include <wx/filedlg.h>
#include <wx/xml/xml.h>
#include <wx/sizer.h>
#include <wx/imagjpeg.h>
#include "mainframe.h"
#include "achievement.h"
#include "achievementframe.h"
#include "achievementlist.h"
MainFrame::MainFrame(const wxString& title)
    :wxFrame(nullptr,
             wxID_ANY,
             title,
             wxDefaultPosition,
             wxSize(400, 400),
             wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)){

        this->SetBackgroundColour(wxColor(33,33,33));

        auto loadFile = new wxButton(this,
                                     wxID_ANY,
                                     "Load",
                                     wxPoint(107, 135),
                                     wxSize(80, 20));
        auto saveFile = new wxButton(this,
                                     wxID_ANY,
                                     "Save",
                                     wxPoint(207, 135),
                                     wxSize(80, 20));
        m_AchievementButton = new wxButton(this,
                                           wxID_ANY,
                                           "Achievements",
                                           wxPoint(157, 215),
                                           wxSize(80, 20));
        m_AchievementButton->Disable();

        m_TextBox = new wxTextCtrl(this,
                                   wxID_ANY,
                                   wxEmptyString,
                                   wxPoint(107, 175),
                                   wxSize(180, 20));
        m_TextBox->Disable();

        loadFile->Bind(wxEVT_BUTTON, &MainFrame::OnLoadButtonClicked, this);
        saveFile->Bind(wxEVT_BUTTON, &MainFrame::OnSaveButtonClicked, this);
        m_AchievementButton->Bind(wxEVT_BUTTON, &MainFrame::OnAchievementButtonClicked, this);
}

void MainFrame::OnLoadButtonClicked(wxCommandEvent &evt) {

    auto fileDialog = new wxFileDialog(this,
                                       _("Load File"),
                                       wxEmptyString,
                                       wxEmptyString,
                                       _("XML Files (*.xml)|*.xml"));

    if(fileDialog->ShowModal() == wxID_OK){

        m_Path = fileDialog->GetPath();

        wxXmlDocument xmlDocument;
        if(!xmlDocument.Load(m_Path, "UTF-8", wxXMLDOC_KEEP_WHITESPACE_NODES))
           return;

        auto xmlCoinNode = xmlDocument.GetRoot()->GetChildren();
        bool success = false;
        while(xmlCoinNode && !success){
            if(xmlCoinNode->GetName() == "coins") {
                m_Value = xmlCoinNode->GetNodeContent();
                success = true;
            }
            else if(xmlCoinNode->GetName() == "achievementsList"){
                m_Value = xmlCoinNode->GetNodeContent();
                size_t start = 0;
                bool loop = true;
                while(m_Value.find(' ',start) != wxNOT_FOUND || loop){
                    wxString extractedAchievement;
                    if(m_Value.find(' ',start) != wxNOT_FOUND)
                        extractedAchievement = m_Value.substr(start,m_Value.find(' ',start)-start);
                    else {
                        extractedAchievement = m_Value.substr(start, m_Value.find('<', start) - start);
                        loop = false;
                    }
                    if(Achievement::AchievementExists(extractedAchievement))
                        m_Achievements.push_back(extractedAchievement);
                    start = m_Value.find(' ', start) + 1;
                }
            }
            xmlCoinNode = xmlCoinNode->GetNext();
        }
        if(!success){
            auto failed = new wxMessageDialog(this,
                                              _("Invalid Risk of Rain profile file"),
                                              _("Failure"),
                                              wxOK);
            failed->ShowModal();
            m_Path = wxEmptyString;
        }
    }
    m_AchievementButton->Enable();
    m_TextBox->Enable();
    m_TextBox->SetValue(m_Value);
}

void MainFrame::OnSaveButtonClicked(wxCommandEvent &evt){

    if(m_TextBox->GetValue() == wxEmptyString){
        auto emptyStringDialog = new wxMessageDialog(this,
                                                     _("Cannot put empty value"),
                                                     _("Error"),
                                                     wxOK_DEFAULT);
        emptyStringDialog->ShowModal();
        return;
    }

    if(m_Value == m_TextBox->GetValue()){
        auto noChanges = new wxMessageDialog(this,
                                             _("No changes made"),
                                             _("Error"),
                                             wxOK_DEFAULT);
        noChanges->ShowModal();
        return;
    }

    m_Value = m_TextBox->GetValue();

    auto dialogConfirm = new wxMessageDialog(this,
                                             _("Are you sure?"),
                                             _("Confirm"),
                                             wxOK_DEFAULT|wxCANCEL);
    if(dialogConfirm->ShowModal() == wxID_OK){

        wxXmlDocument xmlDocument;
        if(!xmlDocument.Load(m_Path, "UTF-8", wxXMLDOC_KEEP_WHITESPACE_NODES))
            return;

        auto xmlCoinNode = xmlDocument.GetRoot()->GetChildren();
        bool success = false;
        while(xmlCoinNode && !success){
            if(xmlCoinNode->GetName() == "coins") {
                xmlCoinNode->GetChildren()->SetContent(m_Value);
                success = true;
            }
            xmlCoinNode = xmlCoinNode->GetNext();
        }

        if(!success){
            auto failed = new wxMessageDialog(this,
                                              _("Unsuccessfully modified :("),
                                              _("Failure"),
                                              wxOK_DEFAULT);
            failed->ShowModal();
            return;
        }

        m_TextBox->SetValue(wxEmptyString);
        xmlDocument.Save(m_Path, 0);
        m_Path = m_Value = wxEmptyString;
        auto successful = new wxMessageDialog(this,
                                              _("Successfully modified!"),
                                              _("Success"),
                                              wxOK_DEFAULT);
        successful->ShowModal();
    }
}

void MainFrame::OnAchievementButtonClicked(wxCommandEvent &evt) {
    auto achievementFrame = new AchievementFrame(this, _("Achievements"));
    achievementFrame->Show();
}

std::vector<wxString> MainFrame::GetAchievements() {
    return m_Achievements;
}
