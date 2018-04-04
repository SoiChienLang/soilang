#include"bullet.h"
#include "Map.h"
bullet::bullet()
{

}
void bullet::getCoord(tankPlayer &t)
{
    if(t.direct==1){pos.X=t.pos.X+4;pos.Y=t.pos.Y;direct=1;}
    else if(t.direct==-1){pos.X=t.pos.X+4;pos.Y=t.pos.Y+8;direct=-1;}
    else if(t.direct==2) {pos.X=t.pos.X+11;pos.Y=t.pos.Y+4;direct=2;}
    else if(t.direct==-2){pos.X=t.pos.X;pos.Y=t.pos.Y+4;direct=-2;}
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
	FillConsoleOutputCharacter(hOut, 127, 1, pos, &garbage);
	FillConsoleOutputAttribute(hOut, 10*16, 1, pos, &garbage);
}
void bullet::eraseConsole()
{
    DWORD garbage = 0;
	FillConsoleOutputAttribute(hOut, LIGHT_AQUA * 16 + LIGHT_AQUA, 1, pos, &garbage);
}
