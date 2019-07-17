#pragma once
#ifndef BOSS_H
#define BOSS_H
#include<cstring>
#include<windows.h>
#include<iostream>
#include"tankPlayer.h"
#include <vector>
#include<time.h>
#define sizeBx 37
#define sizeBy 20

using namespace std;

class boss
{
public:
	int blood;
	boss();
	void setCoord(SHORT index);
	void setStatus();
	void setImage();
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
