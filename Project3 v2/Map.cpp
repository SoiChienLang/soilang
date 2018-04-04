#include"Map.h"
#include<iostream>

using namespace std;

Map::Map(short _xScreeSize, short _yScreenSize, COORD _origin)
{
	outConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	origin = _origin;
	xScreenSize = _xScreeSize;
	yScreenSize = _yScreenSize;
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

void _setclone(int frame[][200],int x,int y,int size)
{
    for(int j=0;j<size;j++){
        int px=x;
        int py=j+y;
        frame[px][py]=1;
    }

}
void setclone(int frame[][200],int x,int y,int size)
{
    for(int i=0;i<size;i++)
    {
        int px=i+x;
        int py=0+y;
        frame[px][py]=1;
    }
}

void setcloneSquare(int frame[][200],int x,int y)
{

}

void setFrame(int frame[][200])
{
    for(short i=0;i<42;i++)
    for(short j=0;j<165;j++)
    frame[i][j]=0;
    _setclone(frame,10,15,150);_setclone(frame,15,60,10);_setclone(frame,20,90,30);_setclone(frame,25,60,30);_setclone(frame,27,60,60);
    setclone(frame,10,60,5);setclone(frame,25,90,3);setclone(frame,20,90,5);setclone(frame,20,120,8);setclone(frame,25,90,3);
    setclone(frame,10,15,24);setclone(frame,20,36,22);setclone(frame,28,60,4);setclone(frame,38,80,7);setclone(frame,38,120,7);setclone(frame,20,145,13);
    _setclone(frame,38,80,40);_setclone(frame,20,120,25);
}
void renderFrame(int frame[][200])
{
    HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD garbage=0;
    for(short i=0;i<42;i++)
    for(short j=0;j<165;j++){
    if(frame[i][j]==1){
        FillConsoleOutputCharacter(hOut, 254,1,{j,i},&garbage);
        FillConsoleOutputAttribute(hOut, 10*16,1,{j,i},&garbage);
    }
    }
}
