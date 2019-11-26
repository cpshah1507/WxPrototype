#include "GridViewFrame.h"
#include "wx/wrapsizer.h"
#include "wx/grid.h"

wxBEGIN_EVENT_TABLE(GridViewFrame, wxFrame)
EVT_CLOSE(GridViewFrame::OnClose)
wxEND_EVENT_TABLE()

/*
This frame demonstrates dynamically creating a grid view and populating data in it with wxWidgets
*/

GridViewFrame::GridViewFrame() : GeneratedFrame(nullptr, wxID_ANY, "Main UI")
{	
	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 500));
	wxBoxSizer* bz = new wxBoxSizer(wxVERTICAL);
	
	wxStaticText* txt1 = new wxStaticText(panel, wxID_ANY, "WxGrid Example with Sample Data", wxDefaultPosition, wxSize(800,50), wxALIGN_CENTER_HORIZONTAL);
	wxFont t_Font = txt1->GetFont();
	t_Font.SetPointSize(16);	
	txt1->SetFont(t_Font);

	bz->Add(txt1);
		
	wxGrid* grid = new wxGrid(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	grid->CreateGrid(10, 5);

	grid->SetRowSize(0, 35);
	grid->SetColSize(0, 120);

	grid->SetCellValue(0, 0, "Header1");
	grid->SetReadOnly(0, 0);
	bz->Add(grid);
	
	grid->SetColFormatFloat(4, 6, 2);
	grid->SetCellValue(0, 4, "3.1415");

	grid->AutoSizeColumns();
	grid->AutoSizeRows();

	panel->SetSizer(bz);
}

void GridViewFrame::OnClose(wxCloseEvent&)
{
	printf("hello");
	this->Destroy();
}
