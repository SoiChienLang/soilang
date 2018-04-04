#include "tankRobot.h"
#include "Map.h"

tankRobot::tankRobot()
{
    setImageDown();
    drawConsole();
}

void tankRobot::setImageUp()
{
	Character cc; cc.character = 0; cc.color = LIGHT_AQUA * 16;
	for (int i = 0; i < 8; i++) for (int j = 0; j < 11; j++) tank.c[i][j] = cc;
	cc.character = 240; cc.color = LIGHT_RED * 16 + BLUE; for (int i = 2; i < 8; i++) { for (int j = 0; j <= 1; j++)tank.c[i][j] = cc; for (int k = 9; k <= 10; k++) tank.c[i][k] = cc; }
	cc.character = 221; cc.color = LIGHT_GREEN * 16 + LIGHT_PURPLE; tank.c[3][2] = tank.c[6][2] = cc;
	cc.character = 222; cc.color = LIGHT_GREEN * 16 + LIGHT_PURPLE; tank.c[3][8] = tank.c[6][8] = cc;
	cc.character = 220; cc.color = LIGHT_GREEN * 16 + BLUE; tank.c[2][2] = tank.c[2][3] = tank.c[2][7] = tank.c[2][8] = tank.c[4][4] = tank.c[4][6] = cc;
	cc.character = 223; cc.color = LIGHT_GREEN * 16; +BLUE; tank.c[6][4] = tank.c[6][6] = tank.c[7][2] = tank.c[7][8] = cc;
	cc.character = 254; cc.color = LIGHT_GREEN * 16 + RED; tank.c[5][5] = cc;
	cc.character = 215; cc.color = BLACK * 16 + WHITE; tank.c[3][5] = tank.c[2][5] = cc;
	cc.character = 206; cc.color = BLACK * 16 + GRAY; tank.c[1][5] = cc;
	cc.character = 210; cc.color = BLACK * 16 + YELLOW; tank.c[0][5] = cc;
	cc.character = 0; cc.color = GRAY * 16; for (int i = 3; i < 8; i++)for (int j = 2; j <= 8; j++) if (tank.c[i][j].character == 0)tank.c[i][j] = cc;
}
void tankRobot::setImageDown()
{
	Character cc; cc.character = 0; cc.color = LIGHT_AQUA * 16;
	for (int i = 0; i < 8; i++) for (int j = 0; j < 11; j++) tank.c[i][j] = cc;
	cc.character = 240; cc.color = LIGHT_RED * 16 + RED; for (int i = 0; i <= 5; i++) { for (int j = 0; j <= 1; j++)tank.c[i][j] = cc; for (int k = 9; k <= 10; k++) tank.c[i][k] = cc; }
	cc.character = 221; cc.color = LIGHT_GREEN * 16 + LIGHT_PURPLE; tank.c[1][2] = tank.c[4][2] = cc;
	cc.character = 222; cc.color = LIGHT_GREEN * 16 + LIGHT_PURPLE; tank.c[1][8] = tank.c[4][8] = cc;
	cc.character = 220; cc.color = LIGHT_GREEN * 16 + BLUE; tank.c[5][2] = tank.c[5][3] = tank.c[5][7] = tank.c[5][8] = tank.c[3][4] = tank.c[3][6] = cc;
	cc.character = 223; cc.color = LIGHT_GREEN * 16; +BLUE; tank.c[1][4] = tank.c[1][6] = tank.c[0][2] = tank.c[0][8] = cc;
	cc.character = 254; cc.color = LIGHT_GREEN * 16 + RED; tank.c[2][5] = cc;
	cc.character = 215; cc.color = BLACK * 16 + WHITE; tank.c[5][5] = tank.c[4][5] = cc;
	cc.character = 206; cc.color = BLACK * 16 + GRAY; tank.c[6][5] = cc;
	cc.character = 210; cc.color = BLACK * 16 + YELLOW; tank.c[7][5] = cc;
	cc.character = 0; cc.color = GRAY * 16; for (int i = 0; i < 5; i++)for (int j = 2; j <= 8; j++) if (tank.c[i][j].character == 0)tank.c[i][j] = cc;
}
void tankRobot::setImageLeft()
{
	Character cc; cc.character = 0; cc.color = LIGHT_AQUA * 16;
	for (int i = 0; i < 8; i++) for (int j = 0; j < 11; j++) tank.c[i][j] = cc;
	cc.character = 91; cc.color = LIGHT_RED * 16 + RED; for (int i = 4; i <= 10; i++) { tank.c[0][i] = tank.c[6][i] = cc; }
	cc.character = 205; cc.color = BLACK * 16 + WHITE; tank.c[3][3] = tank.c[3][2] = tank.c[3][1] = cc;
	cc.character = 181; cc.color = LIGHT_RED * 16 + BLUE; tank.c[3][0] = cc;
	cc.character = 221; cc.color = LIGHT_GREEN * 16 + LIGHT_PURPLE; tank.c[1][10] = tank.c[1][4] = tank.c[5][10] = tank.c[5][4] = cc;
	cc.character = 220; cc.color = LIGHT_GREEN * 16 + LIGHT_BLUE; tank.c[1][8] = tank.c[1][5] = cc;
	cc.character = 223; cc.color = LIGHT_GREEN * 16 + GREEN; tank.c[5][8] = tank.c[5][5] = cc;
	cc.character = 254; cc.color = LIGHT_GREEN * 16 + LIGHT_BLUE; tank.c[3][7] = cc;
	cc.character = 223; cc.color = LIGHT_GREEN * 16 + BLACK; tank.c[2][8] = tank.c[2][6] = cc;
	cc.character = 220; cc.color = LIGHT_GREEN * 16 + BLACK; tank.c[4][8] = tank.c[4][6] = cc;
	cc.character = 0; cc.color = GRAY * 16; for (int i = 1; i <= 5; i++) for (int j = 4; j <= 10; j++) if (tank.c[i][j].character == 0)tank.c[i][j] = cc;
}
void tankRobot::setImageRight()
{
	Character cc; cc.character = 0; cc.color = LIGHT_AQUA * 16;
	for (int i = 0; i < 8; i++) for (int j = 0; j < 11; j++) tank.c[i][j] = cc;
	cc.character = 91; cc.color = LIGHT_RED * 16 + RED; for (int i = 0; i <= 6; i++) { tank.c[0][i] = tank.c[6][i] = cc; }
	cc.character = 205; cc.color = GREEN * 16 + RED; tank.c[3][7] = tank.c[3][8] = tank.c[3][9] = cc;
	cc.character = 181; cc.color = LIGHT_RED * 16 + BLUE; tank.c[3][10] = cc;
	cc.character = 221; cc.color = BLACK * 16 + BLACK; tank.c[1][0] = tank.c[1][6] = tank.c[5][0] = tank.c[5][6] = cc;
	cc.character = 220; cc.color = LIGHT_GREEN * 16 + LIGHT_PURPLE; tank.c[1][2] = tank.c[1][5] = cc;
	cc.character = 223; cc.color = LIGHT_GREEN * 16 + GREEN; tank.c[5][2] = tank.c[5][5] = cc;
	cc.character = 254; cc.color = LIGHT_GREEN * 16 + LIGHT_BLUE; tank.c[3][3] = cc;
	cc.character = 223; cc.color = LIGHT_GREEN * 16 + BLACK; tank.c[2][2] = tank.c[2][4] = cc;
	cc.character = 220; cc.color = LIGHT_GREEN * 16 + BLACK; tank.c[4][2] = tank.c[4][4] = cc;
	cc.character = 0; cc.color = GRAY * 16; for (int i = 1; i <= 5; i++) for (int j = 0; j <= 6; j++) if (tank.c[i][j].character == 0)tank.c[i][j] = cc;
}
void tankRobot::setConsoleCharacter(const Character &c, const COORD &position)
{
	DWORD garbage = 0;
	FillConsoleOutputCharacter(hOut, c.character, 1, position, &garbage);
	FillConsoleOutputAttribute(hOut, c.color, 1, position, &garbage);
}
void tankRobot::eraseConsoleCharacter(const Character &c, const COORD &position)
{
	DWORD garbage = 0;
	FillConsoleOutputAttribute(hOut, LIGHT_AQUA * 16 + LIGHT_AQUA, 1, position, &garbage);
}
void tankRobot::drawConsole()
{
	COORD position;
	position.Y = pos.Y;
	for (int i = 0; i < 8; i++, position.Y++) {
		position.X = pos.X;
		for (int j = 0; j < 11; j++, position.X++) {
		setConsoleCharacter(tank.c[i][j], position);
		}
	}
}
void tankRobot::eraseConsole()
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

void tankRobot::drawConsoleTank(int i,int frame[][200])
{
    srand(time(0));
    direct =(rand()%i)%5-2;
    if (direct == 1&&pos.Y>minY+1&&checkFrame(frame,pos.Y-1,pos.X)==0) {  setImageUp(); eraseConsole(); pos.Y--; }
    else if (direct ==-1&&pos.Y<maxY&&checkFrame(frame,pos.Y+1,pos.X)==0) {  setImageDown(); eraseConsole(); pos.Y++; }
    else if (direct == -2&&pos.X>minX+1&&checkFrame(frame,pos.Y,pos.X-1)==0) {  setImageLeft(); eraseConsole(); pos.X--; }
    else if (direct == 2&&pos.X<maxX&&checkFrame(frame,pos.Y,pos.X+1)==0) {  setImageRight(); eraseConsole(); pos.X++; }
    drawConsole();
}

int tankRobot::checkFrame(int frame[][200],short x,short y)
{
    for(int i=0;i<8;i++)
    for(int j=0;j<11;j++)
    {
        short px=i+x;
        short py=j+y;
        if(frame[px][py]!=0) return 1;
    }
    return 0;
}
void tankRobot::updateLocation(int frame[][200])
{
    for(int i=1;i<8;i++)
    for(int j=1;j<11;j++){
        int px=pos.Y+i;
        int py=pos.X+j;
        frame[px][py]=2;
    }
}
void tankRobot::constructPos(int i)
{
    pos.X=150;
    pos.Y=2;
}

