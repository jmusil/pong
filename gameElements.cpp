#include "gameElements.h"


Bat::Bat(int startPosX, int startPosY, int startWidth, int startHeight, bool isAI)
{
	Width = startWidth;
	Height = startHeight;
	PosX = startPosX;
	PosY = startPosY;
	AI = isAI;
	Speed = 3;
	
	
	
}

Bat::~Bat()
{
	
}

void  Bat::Draw(wxDC& dc)
{
	
	dc.DrawRectangle(PosX, PosY, Width, Height);
}


int Bat::ReturnPosX()
{
	return PosX;
}
int Bat::ReturnPosY()
{
	return PosY;
}
int Bat::ReturnHeight()
{
	return Height;
}

int Bat::ReturnWidth()
{
	return Width;
}

void Bat::SetPosY(wxPoint& loc)
{
	PosY = loc.y;
}

Ball::Ball(int startPosX, int startPosY, int Radius)
{
	PosX = startPosX;
	PosY = startPosY;
	Rad = Radius;
	StepX = 5;
	StepY = 4;
	ScoreAI = 0;
	ScorePlayer = 0;
	forAI = false;
}

Ball::~Ball()
{
	
}

void Ball::Draw(wxDC& dc)
{
	dc.DrawCircle(PosX, PosY, Rad);
	wxFont font = *wxSWISS_FONT;
	font.SetPointSize( 12 );
	font.SetWeight( wxBOLD );
	dc.SetFont( font );
	dc.SetTextForeground( wxColour( *wxWHITE) ); 
	wxString textAI = wxT("AI:");
	wxString AI;
	AI << ScoreAI;
	dc.DrawText( textAI, 30, 30 );
	dc.DrawText( AI, 32, 50 );
	wxString player;
	wxString textPlayer = wxT("Player:");
	player << ScorePlayer;
	dc.DrawText( textPlayer, 650, 30 );
	dc.DrawText( player, 650, 50 );
	
	
}

void Ball::UpdatePosition(wxSize& window, Bat *leftBat, Bat *rightBat)
{
	// top & bottom rebounds
	if (PosY <= (0 + Rad)|| PosY >= (window.GetY() - Rad)) StepY *= -1;
	
	// check left Bat
	if (forAI)
	{
		if (PosX <= (leftBat->ReturnWidth() + Rad))
		{
			if (((PosY - Rad) > leftBat->ReturnPosY()) && ((PosY + Rad) < leftBat->ReturnPosY() + leftBat->ReturnHeight())) 
			{
				StepX *= -1; 
				forAI = false;
				if (((PosY + Rad) <= (leftBat->ReturnPosY() + leftBat->ReturnHeight() / 2)) && StepY > 0 ) StepY *= -1;
				if (((PosY + Rad) >= (rightBat->ReturnPosY() + rightBat->ReturnHeight() / 2)) && StepY < 0) StepY *= -1;
			}
		}
	}
	
	// check right Bat
	if (!forAI)
	{
		if(PosX >= (window.GetX() - rightBat->ReturnWidth() - Rad))
		{
			if (((PosY - Rad) > rightBat->ReturnPosY()) && ((PosY + Rad) < rightBat->ReturnPosY() + rightBat->ReturnHeight())) 
			{
				StepX *= -1;
				forAI = true;
				if (((PosY + Rad) <= (rightBat->ReturnPosY() + rightBat->ReturnHeight() / 2)) && StepY > 0) StepY *= -1;
				if (((PosY + Rad) >= (rightBat->ReturnPosY() + rightBat->ReturnHeight() / 2)) && StepY < 0) StepY *= -1;
			}
		}
	}	
	// check Goal
	if (PosX <= 0 )
		{
			PosX = window.GetX() / 2;
			ScorePlayer++;
		}
	if (PosX >= window.GetX())
		{
			PosX = window.GetX() / 2;
			ScoreAI++;
		}
	PosX += StepX;
	PosY += StepY;
	
}

int Ball::ReturnPosX()
{
	return PosX;
}
int Ball::ReturnPosY()
{
	return PosY;
}

void Bat::UpdatePosition(wxSize& window, wxPoint& ballPos)
{
		if ( PosY + Height/2 > ballPos.y) PosY -= Speed;
		if ( PosY + Height/2 < ballPos.y) PosY += Speed;
		
		if ( (PosY + Height) > window.GetY()) PosY = window.GetY() - Height ;
		if ( PosY < 0) PosY = 0;
}