#pragma once
#include <wx/wxprec.h>
#include "MainApp.h"

wxIMPLEMENT_APP(MainApp);

bool MainApp::OnInit()
{
	wxFrame* frame = NULL;
	frame = new MainFrame();
	if (frame)	
		frame->Show(true);
	return true;
}

int MainApp::OnExit()
{	
	return 0;
}
