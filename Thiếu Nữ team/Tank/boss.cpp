#include "boss.h"
#include "Map.h"

#define timeDelay 10

boss::boss()
{
	status = 0;
	pos.X = 30;
	pos.Y = 4;
	blood=100;
    setImage();
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
}
void boss::drawBlood()
{
	int bl = blood / 5;
	COORD _pos;
	_pos.X = 145;
	_pos.Y = 10;
	DWORD garbage = 0;
	FillConsoleOutputCharacter(hOut, 219 , bl, _pos, &garbage);
	FillConsoleOutputAttribute(hOut, LIGHT_RED, bl, _pos, &garbage);
}
void boss::eraseBlood()
{
	int bl = blood / 5;
	COORD _pos;
	_pos.X = 145;
	_pos.Y = 10;
	DWORD garbage = 0;
	FillConsoleOutputCharacter(hOut, 219 , bl, _pos, &garbage);
	FillConsoleOutputAttribute(hOut, LIGHT_AQUA * 16 + RED, bl, _pos, &garbage);
}
void boss::setImage()
{
	Character cc; cc.character = 0; cc.color = LIGHT_AQUA * 16 + RED;
	for (SHORT i = 0; i < sizeBy; i++) for (SHORT j = 0; j < sizeBx; j++) tank.c[i][j] = cc;
	cc.color=BLACK; cc.character = 219;
	tank.c[0][8]=tank.c[0][28]=
	tank.c[1][9]=tank.c[1][15]=tank.c[1][21]=tank.c[1][27]=
	tank.c[2][10]=tank.c[2][11]=tank.c[2][15]=tank.c[2][16]=tank.c[2][20]=tank.c[2][21]=tank.c[2][25]=tank.c[2][26]=
	tank.c[3][7]=tank.c[3][8]=tank.c[3][28]=tank.c[3][29]=cc;
	tank.c[4][6]=tank.c[4][30]=
	tank.c[5][5]=tank.c[5][31]=
	tank.c[7][5]=tank.c[7][6]=tank.c[7][7]=tank.c[7][8]=
	tank.c[7][28]=tank.c[7][29]=tank.c[7][30]=tank.c[7][31]=
	tank.c[8][4]=tank.c[8][5]=tank.c[8][31]=tank.c[8][32]=
	tank.c[9][2]=tank.c[9][3]=tank.c[9][4]=
	tank.c[9][32]=tank.c[9][33]=tank.c[9][34]=
    tank.c[13][4]=tank.c[13][5]=tank.c[13][32]=tank.c[13][33]=
	tank.c[14][2]=tank.c[14][3]=tank.c[14][33]=tank.c[14][34]=
	tank.c[15][0]=tank.c[15][1]=tank.c[15][2]=tank.c[15][34]=tank.c[15][35]=tank.c[15][36]=
	tank.c[19][18]=
	cc;
	for(int i=10;i<=26;i++) tank.c[3][i]=cc;
	for(int i=9;i<=27;i++) tank.c[4][i]=cc;
	for(int i=10;i<=26;i++) tank.c[7][i]=cc;
	for(int i=8;i<=28;i++) tank.c[8][i]=cc;
	for(int i=6;i<=30;i++) tank.c[11][i]=cc;
	for(int i=4;i<=32;i++) tank.c[12][i]=cc;
	for(int i=7;i<=29;i++) tank.c[13][i]=cc;
	for(int i=11;i<=25;i++) tank.c[15][i]=cc;
	for(int i=13;i<=23;i++) tank.c[16][i]=cc;
	for(int i=15;i<=21;i++) tank.c[17][i]=cc;
	for(int i=17;i<=19;i++) tank.c[18][i]=cc;
	cc.color=LIGHT_YELLOW; cc.character = 219;
	for(int i=8;i<=28;i++) tank.c[5][i]=cc;
	for(int i=9;i<=27;i++) tank.c[6][i]=cc;
	for(int i=8;i<=28;i++) tank.c[9][i]=cc;
	for(int i=7;i<=29;i++) tank.c[10][i]=cc;
	for(int i=9;i<=27;i++) tank.c[14][i]=cc;

}

void boss::setConsoleCharacter(const Character &c, const COORD &position)
{
	DWORD garbage = 0;
	FillConsoleOutputCharacter(hOut, c.character, 1, position, &garbage);
	FillConsoleOutputAttribute(hOut, c.color, 1, position, &garbage);
}
void boss::eraseConsoleCharacter(const Character &c, const COORD &position)
{
	DWORD garbage = 0;
	FillConsoleOutputAttribute(hOut, LIGHT_AQUA * 16 + LIGHT_AQUA, 1, position, &garbage);
}
void boss::drawConsole()
{
	COORD position;
	position.Y = pos.Y;
	for (SHORT i = 0; i < sizeBy; i++, position.Y++) {
		position.X = pos.X;
		for (SHORT j = 0; j < sizeBx; j++, position.X++) {
		setConsoleCharacter(tank.c[i][j], position);
		}
	}

}
void boss::eraseConsole()
{
	COORD position;
	position.Y = pos.Y;
	for (SHORT i = 0; i < sizeBy; i++, position.Y++) {
		position.X = pos.X;
		for (SHORT j = 0; j < sizeBx; j++, position.X++) {
			eraseConsoleCharacter(tank.c[i][j], position);
		}
	}
}

void boss::draw(tankPlayer &t)
{
    static int time =0;
	time++;
	if(time == 10) time = 0;
	
	if(time == 5){
		if(pos.X < t.pos.X && pos.Y < t.pos.Y){
			setImage(); eraseConsole();pos.X++;pos.Y++;
		}
		if(pos.X < t.pos.X && pos.Y > t.pos.Y){
			setImage(); eraseConsole();pos.X++;pos.Y--;
		}
		if(pos.X > t.pos.X && pos.Y < t.pos.Y){
			setImage(); eraseConsole();pos.X--;pos.Y++;
		}
		if(pos.X > t.pos.X && pos.Y > t.pos.Y){
			setImage(); eraseConsole();pos.X--;pos.Y--;
		}
	}
    drawConsole();
	
}


SHORT boss::checkLocal(short x, short y)
{
    for(SHORT i=0;i<sizeBy;i++)
    for(SHORT j=0;j<sizeBx;j++){
        SHORT px=j+pos.X;
        SHORT py=i+pos.Y;
        if(px==x&&py==y) return 1;
    }
    return 0;
}
void boss::setCoord(SHORT index)
{
   
}
