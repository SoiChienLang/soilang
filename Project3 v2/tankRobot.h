#pragma once
#ifndef TANKROBOT_H
#define TANKROBOT_H
#include<cstring>
#include<windows.h>
#include<iostream>
#include "tankPlayer.h"
#include<time.h>

#define maxX 155
#define maxY 35
#define minX 1
#define minY 1
using namespace std;

class tankRobot
{
public:
//    friend class tankPlayer;
	tankRobot();
	void setImageUp();
	void setImageDown();
	void setImageLeft();
	void setImageRight();
	void setConsoleCharacter(const Character & c, const COORD & pos);
	void drawConsole();
	void eraseConsole();
	void eraseConsoleCharacter(const Character &c, const COORD &pos);
	void drawConsoleTank(int i,int frame[][200]);
	int checkFrame(int frame[][200],short x,short y);
	void updateLocation(int frame[][200]);
	void constructPos(int i);
	int direct = 1;
	COORD pos ;
private:
	image tank;
	int check;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
};
#endif
