#pragma once
#pragma once
#ifndef _COLORDISPLAY_H_INCLUDED
#define _COLORDISPLAY_H_INCLUDED

#include <windows.h>
#include <vector>

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

void setFrame(int frame[][200]);
void renderFrame(int frame[][200]);

struct ColorCharacter
{
	short color;
	unsigned char character;
};

class Map
{
public:
	Map(short _xScreeSize, short _yScreenSize, COORD _origin);
	void setColorCharacterAtPosition(const ColorCharacter & colorchar, const COORD & position);
	void renderMap();
private:
	HANDLE outConsole;
	COORD origin;
	short xScreenSize, yScreenSize;
	short backGroundColor = BLACK * 16;
};

#endif
