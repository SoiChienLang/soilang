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
	void setCoord(int index);
	void setStatus();
	void setImageUp();
	void setImageDown();
	void setImageLeft();
	void setImageRight();
	void setConsoleCharacter(const Character & c, const COORD & pos);
	void drawConsole();
	void eraseConsole();
	void eraseConsoleCharacter(const Character &c, const COORD &pos);
	void draw(int , frame &);
	int checkFrame(frame &, short, short );
	int checkLocal(short , short);
	int direct = 1;
	int status;
	void fire();
	COORD pos;
private:
	image tank;
	int check;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
};
#endif
