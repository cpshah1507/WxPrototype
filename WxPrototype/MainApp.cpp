#pragma once
#include <wx/wxprec.h>
#include "MainApp.h"
#include "MainFrame.h"
#include "GridViewFrame.h"

wxIMPLEMENT_APP(MainApp);

bool MainApp::OnInit()
{
	wxFrame* frame = NULL;
	frame = new GridViewFrame();
	if (frame)
		frame->Show(true);
	return true;
}

int MainApp::OnExit()
{	
	return 0;
}
