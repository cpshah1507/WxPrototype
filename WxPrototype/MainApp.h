#pragma once
#include <wx/wxprec.h>
#include "MainFrame.h"

class MainApp : public wxApp {
public:
	virtual bool OnInit();	
	virtual int OnExit();

private:		
};
