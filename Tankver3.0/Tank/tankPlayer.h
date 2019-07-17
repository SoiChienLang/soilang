#pragma once
#ifndef TANKPLAYER_H
#define TANKPLAYER_H
#include<cstring>
#include<windows.h>
#include<iostream>
#include "frame.h"

#define sizeX 9
#define sizeY 5
#define maxX 140-sizeX+1
#define maxY 70
#define minX 1
#define minY 1

using namespace std;

class bullet;

struct Character
{
	short unsigned color;
	unsigned char character;
};
struct image
{
	Character c[30][30];
};
class tankPlayer
{
public:
	tankPlayer();
	void setImageUp();
	void setImageDown();
	void setImageLeft();
	void setImageRight();
	void setConsoleCharacter(const Character & c, const COORD & pos);
	void drawConsole();
	void eraseConsole();
	void eraseConsoleCharacter(const Character &c, const COORD &pos);
	void draw(frame &);
	SHORT checkFrame(frame &,short, short);
	SHORT checkLocal(short , short);
	SHORT direct;
	COORD pos;
private:
	image tank;
	HANDLE hOut ;
};
#endif
