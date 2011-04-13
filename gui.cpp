///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug 25 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menuBar = new wxMenuBar( 0 );
	game = new wxMenu();
		
	wxMenuItem* menuFileExit;
	menuFileExit = new wxMenuItem( game, wxID_EXIT, wxString( _("E&xit") ) + wxT('\t') + wxT("Alt+X"), wxEmptyString, wxITEM_NORMAL );
	game->Append( menuFileExit );
	
	m_menuBar->Append( game, _("&Game") );
	
	stop = new wxMenu();
	wxMenuItem* start_stop;
	start_stop = new wxMenuItem( stop, ID_STOP, wxString( _("S&tart/Stop the game") ) , wxEmptyString, wxITEM_NORMAL );
	stop->Append( start_stop );
	
	m_menuBar->Append( stop, _("&Start/Stop") );
	
	
	this->SetMenuBar( m_menuBar );
	
	m_statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnCloseFrame ) );
	this->Connect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnExitClick ) );
	this->Connect( wxEVT_PAINT, wxPaintEventHandler( MainFrameBase::OnPaint ) );
	this->Connect( wxEVT_ERASE_BACKGROUND, wxEraseEventHandler( MainFrameBase::OnEraseBackground ) );
	this->Connect( wxEVT_MOTION, wxMouseEventHandler( MainFrameBase::OnMouseMove ) );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnCloseFrame ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnExitClick ) );
	this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MainFrameBase::OnPaint ) );
	this->Disconnect( wxEVT_ERASE_BACKGROUND, wxEraseEventHandler( MainFrameBase::OnEraseBackground ) );
	this->Connect( wxEVT_MOTION, wxMouseEventHandler( MainFrameBase::OnMouseMove ) );
}
