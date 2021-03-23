#pragma once
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
    friend class tankPlayer;
	tankRobot();
	void setImageUp();
	void setImageDown();
	void setImageLeft();
	void setImageRight();
	void setConsoleCharacter(const Character & c, const COORD & pos);
	void drawConsole();
	void eraseConsole();
	void eraseConsoleCharacter(const Character &c, const COORD &pos);
	void drawConsoleTank(int i,tankPlayer &p);
	int direct = 1;
	COORD pos = { 80,10};
private:
	image tank;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
};
