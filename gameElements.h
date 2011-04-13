#include <wx/wx.h>

class Bat: public wxFrame
{
	public:
	Bat(int startPosX, int startPosY, int startWidth, int startHeight, bool isAI);
	virtual ~Bat();
	
	void Draw(wxDC& dc);
	void UpdatePosition(wxSize& window, wxPoint& ballPos);
	int ReturnPosX();
	int ReturnPosY();
	int ReturnHeight();
	int ReturnWidth();
	void SetPosY(wxPoint& loc);
	
	protected:
	int Width, Height, PosX, PosY, Speed;
	bool AI;
};

class Ball
{
	public:
	Ball(int startPosX, int startPosY, int Radius);
	virtual ~Ball();
	void Draw(wxDC& dc);
	void UpdatePosition(wxSize& window, Bat *leftBat, Bat *rightBat);
	int ReturnPosX();
	int ReturnPosY();
	int ScoreAI, ScorePlayer;
	
	
	protected:
	int PosX, PosY, Rad, StepX, StepY;
	int dirX, dirY;
	bool forAI;
};
