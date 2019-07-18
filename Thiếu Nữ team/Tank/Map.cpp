#include"Map.h"
#include<iostream>

using namespace std;


Map::Map(short _xScreeSize, short _yScreenSize, COORD _origin)
{
	outConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	origin = _origin;
	xScreenSize = _xScreeSize;
	yScreenSize = _yScreenSize;
	backGroundColor = BLACK * 16;
}
void Map::setColorCharacterAtPosition(const ColorCharacter & colorchar, const COORD & position)
{
	DWORD garbage = 0;
	FillConsoleOutputCharacter(outConsole, colorchar.character, 1, position, &garbage);
	FillConsoleOutputAttribute(outConsole, colorchar.color, 1, position, &garbage);
}
void Map::renderMap()
{
	DWORD garbage = 0;
	COORD pos;
	ColorCharacter cc; cc.color = BRIGHT_WHITE;

	pos.X = origin.X; pos.Y = origin.Y - 1; cc.character = 196;
	FillConsoleOutputCharacter(outConsole, cc.character, xScreenSize, pos, &garbage);
	FillConsoleOutputAttribute(outConsole, cc.color, xScreenSize, pos, &garbage);

	pos.X = origin.X - 1; pos.Y = origin.Y - 1; cc.character = 218;
	setColorCharacterAtPosition(cc, pos);

	pos.X = origin.X + xScreenSize; pos.Y = origin.Y - 1; cc.character = 191;
	setColorCharacterAtPosition(cc, pos);

	pos.X = origin.X; pos.Y = origin.Y + yScreenSize; cc.character = 196;
	FillConsoleOutputCharacter(outConsole, cc.character, xScreenSize, pos, &garbage);
	FillConsoleOutputAttribute(outConsole, cc.color, xScreenSize, pos, &garbage);

	pos.X = origin.X - 1; pos.Y = origin.Y + yScreenSize; cc.character = 192;
	setColorCharacterAtPosition(cc, pos);

	pos.X = origin.X + xScreenSize; pos.Y = origin.Y + yScreenSize; cc.character = 217;
	setColorCharacterAtPosition(cc, pos);

	cc.character = 179;
	short yPosScreen = yScreenSize + origin.Y;
	for (pos.Y = origin.Y; pos.Y < yPosScreen; pos.Y++)
	{
		pos.X = origin.X - 1;
		setColorCharacterAtPosition(cc, pos);
		pos.X = origin.X + xScreenSize;
		setColorCharacterAtPosition(cc, pos);
	}
	pos.X = origin.X; cc.character = ' '; cc.color = LIGHT_AQUA * 16;
	for (pos.Y = origin.Y; pos.Y < yPosScreen; pos.Y++)
	{
		FillConsoleOutputCharacter(outConsole, cc.character, xScreenSize, pos, &garbage);
		FillConsoleOutputAttribute(outConsole, cc.color, xScreenSize, pos, &garbage);
	}
}
