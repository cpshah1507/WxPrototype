#include "MainFrame.h"
#include "wx/wrapsizer.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_CLOSE(MainFrame::OnClose)
wxEND_EVENT_TABLE()

MainFrame::MainFrame() : GeneratedFrame(nullptr, wxID_ANY, "Main UI")
{
	
}

void MainFrame::OnClose(wxCloseEvent&)
{
	printf("hello");
	this->Destroy();
}
