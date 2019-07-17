#include "tankRobot.h"
#include "Map.h"

#define timeDelay 10

tankRobot::tankRobot()
{
    direct =-1;
    setImageDown();
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
}

void tankRobot::setImageUp()
{
	Character cc; cc.character = 0; cc.color = LIGHT_AQUA * 16;
	for (SHORT i = 0; i < sizeY; i++) for (SHORT j = 0; j < sizeX; j++) tank.c[i][j] = cc;
    cc.character=240;cc.color=RED*16+BLACK; for(SHORT i=1;i<5;i++){tank.c[i][0]=tank.c[i][1]=tank.c[i][7]=tank.c[i][8]=cc; }
    cc.character=8;  cc.color=BLACK*16+LIGHT_YELLOW; tank.c[2][2]=tank.c[2][6]=tank.c[3][2]=tank.c[3][6]=cc;
    cc.character=15; cc.color=YELLOW*16+BLACK; for(SHORT i=2;i<=6;i++) tank.c[4][i]=cc;
    cc.character=206;cc.color=LIGHT_RED *16+BLACK; tank.c[0][4]=tank.c[1][4]=cc;
    cc.character=248;cc.color=BLACK*16+LIGHT_YELLOW; tank.c[1][3]=tank.c[1][5]=cc;
    cc.character=7;  cc.color=BLACK*16+LIGHT_YELLOW; tank.c[2][3]=tank.c[2][5]=cc;
    cc.character=30; cc.color=BLACK*16+LIGHT_YELLOW; tank.c[2][4]=cc;
    cc.character=31; cc.color=BLACK*16+LIGHT_YELLOW; tank.c[3][4]=cc;
    cc.character=27; cc.color=BLACK*16+LIGHT_GREEN; tank.c[3][3]=cc;
    cc.character=26; cc.color=BLACK*16+LIGHT_GREEN; tank.c[3][5]=cc;
}
void tankRobot::setImageDown()
{
	Character cc; cc.character = 0; cc.color = LIGHT_AQUA * 16;
	for (SHORT i = 0; i < sizeY; i++) for (SHORT j = 0; j < sizeX; j++) tank.c[i][j] = cc;
    cc.character=240;cc.color=RED*16+BLACK; for(SHORT i=0;i<4;i++){tank.c[i][0]=tank.c[i][1]=tank.c[i][7]=tank.c[i][8]=cc; }
    cc.character=8;  cc.color=BLACK*16+LIGHT_YELLOW; tank.c[1][2]=tank.c[1][6]=tank.c[2][2]=tank.c[2][6]=cc;
    cc.character=15; cc.color=YELLOW*16+BLACK; for(SHORT i=2;i<=6;i++) tank.c[0][i]=cc;
    cc.character=206;cc.color=LIGHT_RED *16+BLACK; tank.c[3][4]=tank.c[4][4]=cc;
    cc.character=248;cc.color=BLACK*16+LIGHT_YELLOW; tank.c[3][3]=tank.c[3][5]=cc;
    cc.character=7;  cc.color=BLACK*16+LIGHT_YELLOW; tank.c[2][3]=tank.c[2][5]=cc;
    cc.character=30; cc.color=BLACK*16+LIGHT_YELLOW; tank.c[1][4]=cc;
    cc.character=31; cc.color=BLACK*16+LIGHT_YELLOW; tank.c[2][4]=cc;
    cc.character=27; cc.color=BLACK*16+LIGHT_GREEN; tank.c[1][3]=cc;
    cc.character=26; cc.color=BLACK*16+LIGHT_GREEN; tank.c[1][5]=cc;
}
void tankRobot::setImageLeft()
{
	Character cc; cc.character = 0; cc.color = LIGHT_AQUA * 16;
	for (SHORT i = 0; i < sizeY; i++) for (SHORT j = 0; j < sizeX; j++) tank.c[i][j] = cc;
    cc.character=0;  cc.color=BLACK*16;      tank.c[1][6]=tank.c[2][6]=tank.c[3][6]=cc;
    cc.character=91; cc.color=RED*16+BLACK;for(SHORT i=2;i<9;i++) {tank.c[0][i]=cc;tank.c[4][i]=cc;}
    cc.character=10; cc.color=BLACK*16+LIGHT_YELLOW;tank.c[1][4]=tank.c[1][5]=tank.c[3][4]=tank.c[3][5]=cc;cc.color=LIGHT_RED*16+BLACK;tank.c[2][0]=cc;
    cc.character=240;cc.color=LIGHT_RED*16+BLACK;tank.c[2][1]=tank.c[2][2]=tank.c[2][3]=cc;
    cc.character=4;  cc.color=BLACK*16+LIGHT_YELLOW;tank.c[2][4]=tank.c[2][5]=cc;
    cc.character=186;cc.color=LIGHT_RED*16+BLACK;tank.c[1][3]=tank.c[3][3]=cc;
    cc.character=222;cc.color=LIGHT_AQUA*16+BLACK;tank.c[1][7]=tank.c[3][7]=cc;
    cc.character=201;cc.color=LIGHT_AQUA*16+BLACK;tank.c[1][2]=cc;
    cc.character=200;cc.color=LIGHT_AQUA*16+BLACK;tank.c[3][2]=cc;
    cc.character=60; cc.color=LIGHT_AQUA*16+BLACK;tank.c[2][7]=cc;
}
void tankRobot::setImageRight()
{
	Character cc; cc.character = 0; cc.color = LIGHT_AQUA * 16;
	for (SHORT i = 0; i < sizeY; i++) for (SHORT j = 0; j < sizeX; j++) tank.c[i][j] = cc;
     cc.character=0;  cc.color=BLACK*16;      tank.c[1][4]=tank.c[2][4]=tank.c[3][4]=cc;
    cc.character=93; cc.color=RED*16+BLACK;for(SHORT i=0;i<7;i++) {tank.c[0][i]=cc;tank.c[4][i]=cc;}
    cc.character=10; cc.color=BLACK*16+LIGHT_YELLOW;tank.c[1][2]=tank.c[1][3]=tank.c[3][2]=tank.c[3][3]=cc;cc.color=LIGHT_RED*16+BLACK;tank.c[2][8]=cc;
    cc.character=240;cc.color=LIGHT_RED*16+BLACK;tank.c[2][5]=tank.c[2][6]=tank.c[2][7]=cc;
    cc.character=4;  cc.color=BLACK*16+LIGHT_YELLOW;tank.c[2][2]=tank.c[2][3]=cc;
    cc.character=186;cc.color=LIGHT_RED*16+BLACK;tank.c[1][5]=tank.c[3][5]=cc;
    cc.character=221;cc.color=LIGHT_AQUA*16+BLACK;tank.c[1][1]=tank.c[3][1]=cc;
    cc.character=187;cc.color=LIGHT_AQUA*16+BLACK;tank.c[1][6]=cc;
    cc.character=188;cc.color=LIGHT_AQUA*16+BLACK;tank.c[3][6]=cc;
    cc.character=62; cc.color=LIGHT_AQUA*16+BLACK;tank.c[2][1]=cc;
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
	for (SHORT i = 0; i < sizeY; i++, position.Y++) {
		position.X = pos.X;
		for (SHORT j = 0; j < sizeX; j++, position.X++) {
		setConsoleCharacter(tank.c[i][j], position);
		}
	}

}
void tankRobot::eraseConsole()
{
	COORD position;
	position.Y = pos.Y;
	for (SHORT i = 0; i < sizeY; i++, position.Y++) {
		position.X = pos.X;
		for (SHORT j = 0; j < sizeX; j++, position.X++) {
			eraseConsoleCharacter(tank.c[i][j], position);
		}
	}
}

void tankRobot::draw(SHORT i,frame &f)
{
    static SHORT _time=0;
    srand(time(0));
    direct =(rand()%i)%5-2;
    if(_time==1){
    if (direct == 1&&pos.Y>minY+1&&checkFrame(f,pos.X,pos.Y-1)==0) {  setImageUp(); eraseConsole(); pos.Y--; }
    else if (direct ==-1&&pos.Y<maxY&&checkFrame(f,pos.X,pos.Y+1)==0) {  setImageDown(); eraseConsole(); pos.Y++; }
    else if (direct == -2&&pos.X>minX+1&&checkFrame(f,pos.X-1,pos.Y)==0) {  setImageLeft(); eraseConsole(); pos.X--; }
    else if (direct == 2&&pos.X<maxX&&checkFrame(f,pos.X+1,pos.Y)==0) {  setImageRight(); eraseConsole(); pos.X++; }
    drawConsole();
    }
    _time++;
    _time%=3;
}

SHORT tankRobot::checkFrame(frame &f, short x,short y)
{
    for(SHORT i=0;i<f.fr.size();i++){
        for(SHORT j=0;j<sizeY;j++)
        for(SHORT k=0;k<sizeX;k++){
            SHORT px=k+x;
            SHORT py=j+y;
            if(f.fr[i].pos.X==px&&f.fr[i].pos.Y==py)
            return 1;
        }
    }
    return 0;
}
SHORT tankRobot::checkLocal(short x, short y)
{
    for(SHORT i=0;i<sizeY;i++)
    for(SHORT j=0;j<sizeX;j++){
        SHORT px=j+pos.X;
        SHORT py=i+pos.Y;
        if(px==x&&py==y) return 1;
    }
    return 0;
}
void tankRobot::setCoord(SHORT index)
{
    for(SHORT i=0;i<7;i++){if(index%7==i) {pos.X=5+19*i;pos.Y=3;}}
}
void tankRobot::fire()
{
    static SHORT time=0;
    if(time<=6) status=1;
    else status=0;
    time++;
    time%=21;
}
