#include "tankPlayer.h"
#include "Map.h"
#include"tankRobot.h"


tankPlayer::tankPlayer()
{
    setImageUp();
    drawConsole();
}

void tankPlayer::setImageUp()
{
	Character cc; cc.character = 0; cc.color = LIGHT_AQUA * 16;
	for (int i = 0; i < 8; i++) for (int j = 0; j < 11; j++) tank.c[i][j] = cc;
	cc.character = 240; cc.color = LIGHT_RED * 16 + RED; for (int i = 2; i < 8; i++) { for (int j = 0; j <= 1; j++)tank.c[i][j] = cc; for (int k = 9; k <= 10; k++) tank.c[i][k] = cc; }
	cc.character = 221; cc.color = LIGHT_GREEN * 16 + LIGHT_YELLOW; tank.c[3][2] = tank.c[6][2] = cc;
	cc.character = 222; cc.color = LIGHT_GREEN * 16 + LIGHT_YELLOW; tank.c[3][8] = tank.c[6][8] = cc;
	cc.character = 220; cc.color = LIGHT_GREEN * 16 + BLACK; tank.c[2][2] = tank.c[2][3] = tank.c[2][7] = tank.c[2][8] = tank.c[4][4] = tank.c[4][6] = cc;
	cc.character = 223; cc.color = LIGHT_GREEN * 16; +BLACK; tank.c[6][4] = tank.c[6][6] = tank.c[7][2] = tank.c[7][8] = cc;
	cc.character = 254; cc.color = LIGHT_GREEN * 16 + LIGHT_BLUE; tank.c[5][5] = cc;
	cc.character = 215; cc.color = LIGHT_RED * 16 + WHITE; tank.c[3][5] = tank.c[2][5] = cc;
	cc.character = 206; cc.color = LIGHT_RED * 16 + GREEN; tank.c[1][5] = cc;
	cc.character = 210; cc.color = LIGHT_RED * 16 + BLUE; tank.c[0][5] = cc;
	cc.character = 0; cc.color = GREEN * 16; for (int i = 3; i < 8; i++)for (int j = 2; j <= 8; j++) if (tank.c[i][j].character == 0)tank.c[i][j] = cc;
}
void tankPlayer::setImageDown()
{
	Character cc; cc.character = 0; cc.color = LIGHT_AQUA * 16;
	for (int i = 0; i < 8; i++) for (int j = 0; j < 11; j++) tank.c[i][j] = cc;
	cc.character = 240; cc.color = LIGHT_RED * 16 + RED; for (int i = 0; i <=5; i++) { for (int j = 0; j <= 1; j++)tank.c[i][j] = cc; for (int k = 9; k <= 10; k++) tank.c[i][k] = cc; }
	cc.character = 221; cc.color = LIGHT_GREEN * 16 + LIGHT_YELLOW; tank.c[1][2] = tank.c[4][2] = cc;
	cc.character = 222; cc.color = LIGHT_GREEN * 16 + LIGHT_YELLOW; tank.c[1][8] = tank.c[4][8] = cc;
	cc.character = 220; cc.color = LIGHT_GREEN * 16 + BLACK; tank.c[5][2] = tank.c[5][3] = tank.c[5][7] =  tank.c[5][8] = tank.c[3][4] = tank.c[3][6] = cc;
	cc.character = 223; cc.color = LIGHT_GREEN * 16; +BLACK; tank.c[1][4] = tank.c[1][6] = tank.c[0][2] = tank.c[0][8] = cc;
	cc.character = 254; cc.color = LIGHT_GREEN * 16 + LIGHT_BLUE; tank.c[2][5] = cc;
	cc.character = 215; cc.color = LIGHT_RED * 16 + WHITE; tank.c[5][5] = tank.c[4][5] = cc;
	cc.character = 206; cc.color = LIGHT_RED * 16 + GREEN; tank.c[6][5] = cc;
	cc.character = 210; cc.color = LIGHT_RED * 16 + BLUE; tank.c[7][5] = cc;
	cc.character = 0; cc.color = GREEN * 16; for (int i = 0; i < 5; i++)for (int j = 2; j <= 8; j++) if (tank.c[i][j].character == 0)tank.c[i][j] = cc;
}
void tankPlayer::setImageLeft()
{
	Character cc; cc.character = 0; cc.color = LIGHT_AQUA * 16;
	for (int i = 0; i < 8; i++) for (int j = 0; j < 11; j++) tank.c[i][j] = cc;
	cc.character = 91; cc.color = LIGHT_RED * 16 + RED; for (int i = 4; i <= 10; i++) { tank.c[0][i] = tank.c[6][i] = cc; }
	cc.character = 205; cc.color = GREEN * 16 + RED; tank.c[3][3] = tank.c[3][2] = tank.c[3][1] = cc;
	cc.character = 181; cc.color = LIGHT_RED * 16 + BLUE; tank.c[3][0] = cc;
	cc.character = 221; cc.color = BLACK * 16 + BLACK; tank.c[1][10] = tank.c[1][4] = tank.c[5][10] = tank.c[5][4] = cc;
	cc.character = 220; cc.color = LIGHT_GREEN * 16 + GREEN; tank.c[1][8] = tank.c[1][5] = cc;
	cc.character = 223; cc.color = LIGHT_GREEN * 16 + GREEN; tank.c[5][8] = tank.c[5][5] = cc;
	cc.character = 254; cc.color = LIGHT_GREEN * 16 + LIGHT_BLUE; tank.c[3][7] = cc;
	cc.character = 223; cc.color = LIGHT_GREEN * 16 + BLACK; tank.c[2][8] = tank.c[2][6] = cc;
	cc.character = 220; cc.color = LIGHT_GREEN * 16 + BLACK; tank.c[4][8] = tank.c[4][6] = cc;
	cc.character = 0; cc.color = GREEN * 16; for (int i = 1; i <= 5; i++) for (int j = 4; j <= 10; j++) if (tank.c[i][j].character == 0)tank.c[i][j] = cc;
}
void tankPlayer::setImageRight()
{
	Character cc; cc.character = 0; cc.color = LIGHT_AQUA * 16;
	for (int i = 0; i < 8; i++) for (int j = 0; j < 11; j++) tank.c[i][j] = cc;
	cc.character = 91; cc.color = LIGHT_RED * 16 + RED; for (int i = 0; i <= 6; i++) { tank.c[0][i] = tank.c[6][i] = cc; }
	cc.character = 205; cc.color = GREEN * 16 + RED; tank.c[3][7] = tank.c[3][8] = tank.c[3][9] = cc;
	cc.character = 181; cc.color = LIGHT_RED * 16 + BLUE; tank.c[3][10] = cc;
	cc.character = 221; cc.color = BLACK * 16 + BLACK; tank.c[1][0] = tank.c[1][6] = tank.c[5][0] = tank.c[5][6] = cc;
	cc.character = 220; cc.color = LIGHT_GREEN * 16 + GREEN; tank.c[1][2] = tank.c[1][5] = cc;
	cc.character = 223; cc.color = LIGHT_GREEN * 16 + GREEN; tank.c[5][2] = tank.c[5][5] = cc;
	cc.character = 254; cc.color = LIGHT_GREEN * 16 + LIGHT_BLUE; tank.c[3][3] = cc;
	cc.character = 223; cc.color = LIGHT_GREEN * 16 + BLACK; tank.c[2][2] = tank.c[2][4] = cc;
	cc.character = 220; cc.color = LIGHT_GREEN * 16 + BLACK; tank.c[4][2] = tank.c[4][4] = cc;
	cc.character = 0; cc.color = GREEN * 16; for (int i = 1; i <= 5; i++) for (int j = 0; j <= 6; j++) if (tank.c[i][j].character == 0)tank.c[i][j] = cc;
}
void tankPlayer::setConsoleCharacter(const Character &c, const COORD &position)
{
	DWORD garbage = 0;
	FillConsoleOutputCharacter(hOut, c.character, 1, position, &garbage);
	FillConsoleOutputAttribute(hOut, c.color, 1, position, &garbage);
}
void tankPlayer::eraseConsoleCharacter(const Character &c, const COORD &position)
{
	DWORD garbage = 0;
	FillConsoleOutputAttribute(hOut, LIGHT_AQUA * 16 + LIGHT_AQUA, 1, position, &garbage);
}
void tankPlayer ::drawConsole()
{
	COORD position;
	position.Y = pos.Y;
	for (int i = 0; i < 8; i++,position.Y++) {
		position.X = pos.X;
		for (int j = 0; j < 11; j++, position.X++) {
			setConsoleCharacter(tank.c[i][j], position);
		}
	}
}
void tankPlayer::eraseConsole()
{
	COORD position;
	position.Y = pos.Y;
	for (int i = 0; i < 8; i++, position.Y++) {
		position.X = pos.X;
		for (int j = 0; j < 11; j++, position.X++) {
			eraseConsoleCharacter(tank.c[i][j], position);
		}
	}
}

void tankPlayer::drawConsoleTank()
{
	if (GetAsyncKeyState(VK_UP)&&pos.Y>minY) { direct = 1; setImageUp(); eraseConsole(); pos.Y--;  }
	if (GetAsyncKeyState(VK_DOWN)&&pos.Y<maxY) { direct = -1; setImageDown(); eraseConsole(); pos.Y++; }
	if (GetAsyncKeyState(VK_LEFT)&&pos.X>minX) { direct = -2; setImageLeft(); eraseConsole(); pos.X--; }
	if (GetAsyncKeyState(VK_RIGHT)&&pos.X<maxX) { direct = 2; setImageRight(); eraseConsole(); pos.X++; }
	drawConsole();
}
