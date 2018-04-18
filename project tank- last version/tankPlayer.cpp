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
	for (int i = 0; i < sizeY; i++) for (int j = 0; j < sizeX; j++) tank.c[i][j] = cc;
    cc.character=240;cc.color=RED*16+BLACK; for(int i=1;i<5;i++){tank.c[i][0]=tank.c[i][1]=tank.c[i][7]=tank.c[i][8]=cc; }
    cc.character=8;  cc.color=BLACK*16+LIGHT_YELLOW; tank.c[2][2]=tank.c[2][6]=tank.c[3][2]=tank.c[3][6]=cc;
    cc.character=15; cc.color=YELLOW*16+BLACK; for(int i=2;i<=6;i++) tank.c[4][i]=cc;
    cc.character=206;cc.color=LIGHT_RED *16+BLACK; tank.c[0][4]=tank.c[1][4]=cc;
    cc.character=248;cc.color=LIGHT_AQUA*16+BLACK; tank.c[1][3]=tank.c[1][5]=cc;
    cc.character=7;  cc.color=LIGHT_BLUE*16+BLACK; tank.c[2][3]=tank.c[2][5]=cc;
    cc.character=30; cc.color=LIGHT_BLUE*16+LIGHT_YELLOW; tank.c[2][4]=cc;
    cc.character=31; cc.color=LIGHT_BLUE*16+BLACK; tank.c[3][4]=cc;
    cc.character=27; cc.color=LIGHT_BLUE*16+BLACK; tank.c[3][3]=cc;
    cc.character=26; cc.color=LIGHT_BLUE*16+BLACK; tank.c[3][5]=cc;
}
void tankPlayer::setImageDown()
{
	Character cc; cc.character = 0; cc.color = LIGHT_AQUA * 16;
	for (int i = 0; i < sizeY; i++) for (int j = 0; j < sizeX; j++) tank.c[i][j] = cc;
    cc.character=240;cc.color=RED*16+BLACK; for(int i=0;i<4;i++){tank.c[i][0]=tank.c[i][1]=tank.c[i][7]=tank.c[i][8]=cc; }
    cc.character=8;  cc.color=BLACK*16+LIGHT_YELLOW; tank.c[1][2]=tank.c[1][6]=tank.c[2][2]=tank.c[2][6]=cc;
    cc.character=15; cc.color=YELLOW*16+BLACK; for(int i=2;i<=6;i++) tank.c[0][i]=cc;
    cc.character=206;cc.color=LIGHT_RED *16+BLACK; tank.c[3][4]=tank.c[4][4]=cc;
    cc.character=248;cc.color=LIGHT_AQUA*16+BLACK; tank.c[3][3]=tank.c[3][5]=cc;
    cc.character=7;  cc.color=LIGHT_BLUE*16+BLACK; tank.c[2][3]=tank.c[2][5]=cc;
    cc.character=30; cc.color=LIGHT_BLUE*16+BLACK; tank.c[1][4]=cc;
    cc.character=31; cc.color=LIGHT_BLUE*16+BLACK; tank.c[2][4]=cc;
    cc.character=27; cc.color=LIGHT_BLUE*16+BLACK; tank.c[1][3]=cc;
    cc.character=26; cc.color=LIGHT_BLUE*16+BLACK; tank.c[1][5]=cc;
}
void tankPlayer::setImageLeft()
{
	Character cc; cc.character = 0; cc.color = LIGHT_AQUA * 16;
	for (int i = 0; i < sizeY; i++) for (int j = 0; j < sizeX; j++) tank.c[i][j] = cc;
	cc.character=0;  cc.color=LIGHT_BLUE*16;      tank.c[1][6]=tank.c[2][6]=tank.c[3][6]=cc;
    cc.character=91; cc.color=RED*16+BLACK;for(int i=2;i<9;i++) {tank.c[0][i]=cc;tank.c[4][i]=cc;}
    cc.character=10; cc.color=LIGHT_BLUE*16+LIGHT_YELLOW;tank.c[1][4]=tank.c[1][5]=tank.c[3][4]=tank.c[3][5]=cc;cc.color=LIGHT_RED*16+BLACK;tank.c[2][0]=cc;
    cc.character=240;cc.color=LIGHT_RED*16+BLACK;tank.c[2][1]=tank.c[2][2]=tank.c[2][3]=cc;
    cc.character=4;  cc.color=LIGHT_BLUE*16+BLACK;tank.c[2][4]=tank.c[2][5]=cc;
    cc.character=186;cc.color=LIGHT_RED*16+BLACK;tank.c[1][3]=tank.c[3][3]=cc;
    cc.character=222;cc.color=LIGHT_AQUA*16+BLACK;tank.c[1][7]=tank.c[3][7]=cc;
    cc.character=201;cc.color=LIGHT_AQUA*16+BLACK;tank.c[1][2]=cc;
    cc.character=200;cc.color=LIGHT_AQUA*16+BLACK;tank.c[3][2]=cc;
    cc.character=60; cc.color=LIGHT_AQUA*16+BLACK;tank.c[2][7]=cc;
}
void tankPlayer::setImageRight()
{
	Character cc; cc.character = 0; cc.color = LIGHT_AQUA * 16;
    for (int i = 0; i < sizeY; i++) for (int j = 0; j < sizeX; j++) tank.c[i][j] = cc;
    cc.character=0;  cc.color=LIGHT_BLUE*16;      tank.c[1][4]=tank.c[2][4]=tank.c[3][4]=cc;
    cc.character=93; cc.color=RED*16+BLACK;for(int i=0;i<7;i++) {tank.c[0][i]=cc;tank.c[4][i]=cc;}
    cc.character=10; cc.color=LIGHT_BLUE*16+LIGHT_YELLOW;tank.c[1][2]=tank.c[1][3]=tank.c[3][2]=tank.c[3][3]=cc;cc.color=LIGHT_RED*16+BLACK;tank.c[2][8]=cc;
    cc.character=240;cc.color=LIGHT_RED*16+BLACK;tank.c[2][5]=tank.c[2][6]=tank.c[2][7]=cc;
    cc.character=4;  cc.color=LIGHT_BLUE*16+BLACK;tank.c[2][2]=tank.c[2][3]=cc;
    cc.character=186;cc.color=LIGHT_RED*16+BLACK;tank.c[1][5]=tank.c[3][5]=cc;
    cc.character=221;cc.color=LIGHT_AQUA*16+BLACK;tank.c[1][1]=tank.c[3][1]=cc;
    cc.character=187;cc.color=LIGHT_AQUA*16+BLACK;tank.c[1][6]=cc;
    cc.character=188;cc.color=LIGHT_AQUA*16+BLACK;tank.c[3][6]=cc;
    cc.character=62; cc.color=LIGHT_AQUA*16+BLACK;tank.c[2][1]=cc;
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
	for (int i = 0; i < sizeY; i++,position.Y++) {
		position.X = pos.X;
		for (int j = 0; j < sizeX; j++, position.X++) {
			setConsoleCharacter(tank.c[i][j], position);
		}
	}
	if(direct==1) {gotoxy(pos.X+4,pos.Y-10);}
	if(direct==-1){gotoxy(pos.X+4,pos.Y+sizeY);}
}
void tankPlayer::eraseConsole()
{
	COORD position;
	position.Y = pos.Y;
	for (int i = 0; i < sizeY; i++, position.Y++) {
		position.X = pos.X;
		for (int j = 0; j < sizeX; j++, position.X++) {
			eraseConsoleCharacter(tank.c[i][j], position);
		}
	}
}

void tankPlayer::draw(frame &f)
{
	if (GetAsyncKeyState(VK_UP)&&pos.Y>minY&&checkFrame(f,pos.X,pos.Y-1)==0){ direct = 1; setImageUp(); eraseConsole(); pos.Y--;  }
	if (GetAsyncKeyState(VK_DOWN)&&pos.Y<maxY&&checkFrame(f,pos.X,pos.Y+1)==0) { direct = -1; setImageDown(); eraseConsole(); pos.Y++; }
	if (GetAsyncKeyState(VK_LEFT)&&pos.X>minX&&checkFrame(f,pos.X-1,pos.Y)==0) { direct = -2; setImageLeft(); eraseConsole(); pos.X--; }
	if (GetAsyncKeyState(VK_RIGHT)&&pos.X<maxX&&checkFrame(f,pos.X+1,pos.Y)==0) { direct = 2; setImageRight(); eraseConsole(); pos.X++; }
	drawConsole();
}
int tankPlayer::checkFrame(frame &f, short x, short y)
{
    for(int i=0;i<f.fr.size();i++){
        for(int j=0;j<sizeY;j++)
        for(int k=0;k<sizeX;k++){
            int px=k+x;
            int py=j+y;
            if(f.fr[i].pos.X==px&&f.fr[i].pos.Y==py)
            return 1;
        }
    }
    return 0;
}
int tankPlayer::checkLocal(short x, short y)
{
    for(int i=0;i<sizeY;i++)
    for(int j=0;j<sizeX;j++){
        int px=j+pos.X;
        int py=i+pos.Y;
        if(px==x&&py==y) return 1;
    }
    return 0;
}
