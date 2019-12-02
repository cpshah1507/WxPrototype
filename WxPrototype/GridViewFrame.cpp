#include "GridViewFrame.h"
#include <random>

//#include "wx/wrapsizer.h"

#define UPDATE_DATA_TIMER_ID 1
#define COL_SIZE 5
#define ROW_SIZE 10


wxBEGIN_EVENT_TABLE(GridViewFrame, wxFrame)
EVT_CLOSE(GridViewFrame::OnClose)
EVT_TIMER(UPDATE_DATA_TIMER_ID, GridViewFrame::UpdateData)
wxEND_EVENT_TABLE()

/*
This frame demonstrates dynamically creating a grid view and populating data in it with wxWidgets
*/

GridViewFrame::GridViewFrame() : GeneratedFrame(nullptr, wxID_ANY, "Main UI"),
	m_grid(nullptr)
{	
	srand(time(NULL));

	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 500));

	// Adding a vertical box sizer to add title first and then content
	wxBoxSizer* bz = new wxBoxSizer(wxVERTICAL);
	
	// Adding title of the frame with larger font
	wxStaticText* txt1 = new wxStaticText(panel, wxID_ANY, "WxGrid Example with Sample Data", wxDefaultPosition, wxSize(800,50), wxALIGN_CENTER_HORIZONTAL);
	wxFont t_Font = txt1->GetFont();
	t_Font.SetPointSize(16);	
	txt1->SetFont(t_Font);

	bz->Add(txt1);
		
	// Adding a box horizontal box sizer to add elements like grid
	wxGrid* grid = new wxGrid(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	m_grid = grid;

	grid->CreateGrid(ROW_SIZE, COL_SIZE);

	// Set custom row and column size for first row and column
	grid->SetRowSize(0, 35);
	grid->SetColSize(0, 120);

	// Add headers for all columns
	for (int i = 0; i < COL_SIZE; i++)
	{
		grid->SetCellValue(0, i, "Header" + std::to_string(i+1));
		grid->SetReadOnly(0, i);
	}
		
	bz->Add(grid);
	
	// Format cell and set cell value of a specific cell
	grid->SetColFormatFloat(4, 6, 2);
	grid->SetCellValue(1, 4, "3.1415");

	// Disable editing for the entire grid
	// grid->EnableEditing(false);

	// Auto re-size columns and rows based on data filled up in it
	grid->AutoSizeColumns();
	grid->AutoSizeRows();

	panel->SetSizer(bz);

	// Configure timer to run a specific function at certain time interval
	UpdateDataTimer.SetOwner(this, UPDATE_DATA_TIMER_ID);
	UpdateDataTimer.Start(1000);
}

void GridViewFrame::OnClose(wxCloseEvent&)
{	
	this->Destroy();
}

void GridViewFrame::UpdateData(wxTimerEvent&)
{
	if (m_grid)
	{
		auto rand_num = 0;
		for (int i = 1; i < ROW_SIZE; i++)
		{
			rand_num = (rand() % 10) + 1;
			m_grid->SetCellValue(i, 4, std::to_string(rand_num));
		}
	}
}