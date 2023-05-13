#include "app.h"
#include "mainframe.h"
bool App::OnInit(){
    if(!wxApp::OnInit())
        return false;
    auto frame = new MainFrame(_("Title"));
    frame->SetTitle(_("RoR2 Lunar Coin Modifier"));
    frame->Show();
    return true;
}