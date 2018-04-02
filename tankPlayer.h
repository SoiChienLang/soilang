#pragma once
#include<cstring>
#include<windows.h>
#include<iostream>


using namespace std;

class bullet;

struct Character
{
	short unsigned color;
	unsigned char character;
};
struct image
{
	Character c[8][11];
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
	void drawConsoleTank();
	int direct = 1;
	COORD pos = {50,25};
	friend void getPos(tankPlayer &t,bullet &b);
private:
	image tank;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
};
