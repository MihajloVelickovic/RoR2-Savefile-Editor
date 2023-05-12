#include "frame.h"
#include <wx/filedlg.h>
#include <wx/xml/xml.h>
#include <wx/sizer.h>
Frame::Frame(const wxString& title)
    :wxFrame(nullptr, wxID_ANY, title){

        this->SetMaxSize(wxSize(400,400));
        this->SetMinSize(wxSize(400,400));
        this->SetBackgroundColour(wxColor(33,33,33));

        auto loadFile = new wxButton(this,
                                     wxID_ANY,
                                     "Load",
                                     wxPoint(100,180),
                                     wxSize(80,20));
        auto saveFile = new wxButton(this,
                                     wxID_ANY,
                                     "Save",
                                     wxPoint(200,180),
                                     wxSize(80,20));

        auto sizer =  new wxBoxSizer(wxVERTICAL);
        sizer->Add(loadFile, 1, wxEXPAND|wxLEFT, 10);
        sizer->Add(saveFile, 1, wxEXPAND|wxRIGHT, 10);

        m_TextBox = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(100,220), wxSize(160,20));
        m_TextBox->Disable();

        loadFile->Bind(wxEVT_BUTTON, &Frame::OnButtonClicked, this);
}

void Frame::OnButtonClicked(wxCommandEvent &evt) {

    auto fileDialog = new wxFileDialog(this,
                                       _("Load File"),
                                       wxEmptyString,
                                       wxEmptyString,
                                       _("XML Files (*.xml)|*.xml"));

    if(fileDialog->ShowModal() == wxID_OK){
        wxArrayString files;
        fileDialog->GetPaths(files);
        wxXmlDocument xmlDocument;
        //as only one file is expected to be selected, files[0] is used to load
        if(!xmlDocument.Load(files[0],"UTF-8", wxXMLDOC_KEEP_WHITESPACE_NODES))
           return;
        auto xmlCoinNode = xmlDocument.GetRoot()->GetChildren();
        while(xmlCoinNode){
            if(xmlCoinNode->GetName()=="coins") {
                m_Value = xmlCoinNode->GetNodeContent();
                break;
            }
            xmlCoinNode = xmlCoinNode->GetNext();
        }
    }
    m_TextBox->Enable();
    m_TextBox->SetValue(m_Value);
}