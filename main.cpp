#include "main.h"

#include <wx/dcbuffer.h>

// initialize the application
IMPLEMENT_APP(MainApp);

////////////////////////////////////////////////////////////////////////////////
// application class implementation 
////////////////////////////////////////////////////////////////////////////////

bool MainApp::OnInit()
{
	SetTopWindow( new MainFrame( NULL ) );
	GetTopWindow()->Show();
	// true = enter the main loop
	return true;
}

////////////////////////////////////////////////////////////////////////////////
// main application frame implementation 
////////////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame(wxWindow *parent) : MainFrameBase( parent )
{
	
	SetBackgroundStyle( wxBG_STYLE_CUSTOM );
	wxSize wndInitSize = GetClientSize();
	m_Game = new Game(this);
	timerRunning = true;

}

MainFrame::~MainFrame()
{
	delete m_Game;
}

void MainFrame::OnCloseFrame(wxCloseEvent& event)
{
	Destroy();
}

void MainFrame::OnExitClick(wxCommandEvent& event)
{
	if (event.GetId() == ID_STOP)
	{
		if(this->timerRunning)
		{
			this->m_Game->StopTimer();
			this->timerRunning = false;
		}else
		{
			this->m_Game->StartTimer();
			this->timerRunning = true;
		}
	} 
	else 
	{
		Destroy();
	}
}

void MainFrame::OnEraseBackground(wxEraseEvent& event)
{
	// this function intentionally left blank (:
}

void MainFrame::OnMouseMove(wxMouseEvent& event)
{
	
	this->m_Game->SetMouseMove(event.GetPosition());
}

void MainFrame::OnPaint(wxPaintEvent& event)
{
	wxAutoBufferedPaintDC dc(this);
	
	dc.SetBackground( wxBrush( wxColour(0, 0, 0), wxSOLID ) );
	dc.Clear();
		
	wxSize wndSize = GetClientSize();
	dc.SetPen( wxPen( wxColour( 255, 255, 255), 1, wxSOLID ) );
	dc.SetBrush(wxColour( 255, 255, 255));
	
	// draw game
	m_Game->Draw(dc);
	
	// cleanup
	dc.SetFont( wxNullFont );
	dc.SetBrush( wxNullBrush );
	dc.SetPen( wxNullPen );
}

Game::Game(wxFrame* window)
{
	x = y = 0;
	m_ParentFrame = window;
	wxSize dim = m_ParentFrame->GetSize();
		
	m_AiBat = new Bat(0,dim.y/2-30,10,60,1);
	m_PlayerBat = new Bat(785,dim.y/2-30,10,60,0);
	m_Ball = new Ball(dim.x/2, dim.y/2,10);
	wxPoint ballPos;
	// Spusteni casovace
	Start(25);
	
}

Game::~Game()

{
	delete m_AiBat;
	delete m_PlayerBat;
	delete m_Ball;
	Stop();
}

void Game::Notify()
{
	wxSize wndSize = m_ParentFrame->GetClientSize();
	m_Ball->UpdatePosition(wndSize, m_AiBat,m_PlayerBat);
	ballPos.x = m_Ball->ReturnPosX();
	ballPos.y = m_Ball->ReturnPosY();
	m_AiBat->UpdatePosition(wndSize, ballPos);
	m_ParentFrame->Refresh();
}
void Game::SetMouseMove(wxPoint pos)
{
	m_PlayerBat->SetPosY(pos);
}

void Game::Draw(wxDC& dc)
{
	m_Ball->Draw(dc);
	m_AiBat->Draw(dc);
	m_PlayerBat->Draw(dc);
	dc.SetPen( wxPen( wxColour( 255, 255, 255), 1, wxSHORT_DASH ) );
	dc.DrawLine(400, 0, 400, 500);
	dc.SetPen( wxPen( wxColour( 255, 255, 255), 1, wxSOLID ) );
}

void Game::StartTimer()
{
	Start(25);
	
}
void Game::StopTimer()
{
	Stop();
	
}