#pragma once
#include <wx/wxprec.h>
#include <wx/propgrid/propgrid.h>
#include <wx/spinctrl.h>
#include <wx/timer.h>
#include "GeneratedFrame.h"
#include "wx/grid.h"

/*
This frame demonstrates dynamically creating a grid view and populating data in it with wxWidgets
*/

class GridViewFrame : public GeneratedFrame {
public:
	GridViewFrame();
	void OnClose(wxCloseEvent& event);

protected:
	
private:
	wxTimer UpdateDataTimer;
	void UpdateData(wxTimerEvent&);
	wxGrid* m_grid;

	wxDECLARE_EVENT_TABLE();
};
