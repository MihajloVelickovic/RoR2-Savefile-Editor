#include "frame.h"

Frame::Frame(const wxString& title)
    :wxFrame(nullptr, wxID_ANY, title){
    this->SetBackgroundColour(wxColor(255,200,0));
    auto addDriver = new wxButton(this,
                                  wxID_ANY,
                                  "Dodaj Vozaca",
                                  wxPoint(10,100),
                                  wxSize(80,20));

}

