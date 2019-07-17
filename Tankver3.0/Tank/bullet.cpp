#include"bullet.h"
#include "Map.h"

bullet::bullet()
{
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);
}
void bullet::getCoord(tankPlayer &t)
{
    index=0;
    if(t.direct==1){pos.X=t.pos.X+4;pos.Y=t.pos.Y;direct=1;}
    else if(t.direct==-1){pos.X=t.pos.X+4;pos.Y=t.pos.Y+5;direct=-1;}
    else if(t.direct==2) {pos.X=t.pos.X+8;pos.Y=t.pos.Y+2;direct=2;}
    else if(t.direct==-2){pos.X=t.pos.X;pos.Y=t.pos.Y+2;direct=-2;}
}
void bullet::getCoordRobot(tankRobot &r)
{
    index=1;
    if(r.direct==1){pos.X=r.pos.X+4;pos.Y=r.pos.Y;direct=1;}
    else if(r.direct==-1){pos.X=r.pos.X+4;pos.Y=r.pos.Y+4;direct=-1;}
    else if(r.direct==2) {pos.X=r.pos.X+8;pos.Y=r.pos.Y+2;direct=2;}
    else if(r.direct==-2){pos.X=r.pos.X;pos.Y=r.pos.Y+2;direct=-2;}
}
void bullet::fire()
{
    if(direct==1) {eraseConsole();pos.Y--;}
    else if(direct==-1) {eraseConsole();pos.Y++;}
    else if(direct==2) {eraseConsole();pos.X++;}
    else if(direct==-2) {eraseConsole();pos.X--;}
    drawConsole();
}
void bullet::drawConsole()
{
    DWORD garbage = 0;
	if(direct==1)       FillConsoleOutputCharacter(hOut, 223, 1, pos, &garbage);
	else if(direct==-1) FillConsoleOutputCharacter(hOut, 223, 1, pos, &garbage);
	else if(direct==2)  FillConsoleOutputCharacter(hOut, 223, 1, pos, &garbage);
	else if(direct==-2) FillConsoleOutputCharacter(hOut, 223, 1, pos, &garbage);
	FillConsoleOutputAttribute(hOut, LIGHT_AQUA*16+RED, 1, pos, &garbage);
}
void bullet::eraseConsole()
{
    DWORD garbage = 0;
	FillConsoleOutputAttribute(hOut, LIGHT_AQUA * 16 + LIGHT_AQUA, 1, pos, &garbage);
}


