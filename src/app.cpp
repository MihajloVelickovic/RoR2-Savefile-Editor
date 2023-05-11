#include "app.h"
#include "frame.h"
bool App::OnInit(){
    if(!wxApp::OnInit())
        return false;
    auto frame = new Frame(_("Title"));
    frame->SetTitle(_("Lista Vozaca"));
    frame->Show();
    return true;
}