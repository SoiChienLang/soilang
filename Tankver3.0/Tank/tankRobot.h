#pragma once
#ifndef TANKROBOT_H
#define TANKROBOT_H
#include<cstring>
#include<windows.h>
#include<iostream>
#include "tankPlayer.h"
#include <vector>
#include<time.h>


using namespace std;

class tankRobot
{
public:
//    friend class tankPlayer;
	tankRobot();
	void setCoord(SHORT index);
	void setStatus();
	void setImageUp();
	void setImageDown();
	void setImageLeft();
	void setImageRight();
	void setConsoleCharacter(const Character & c, const COORD & pos);
	void drawConsole();
	void eraseConsole();
	void eraseConsoleCharacter(const Character &c, const COORD &pos);
	void draw(SHORT , frame &);
	SHORT checkFrame(frame &, short, short );
	SHORT checkLocal(short , short);
	SHORT direct ;
	SHORT status;
	void fire();
	COORD pos;
private:
	image tank;
	SHORT check;
	HANDLE hOut;
};
#endif
