#include<conio.h>
#include "Map.h"
#include "tankPlayer.h"
#include "tankRobot.h"

using namespace std;


Map map(165, 42, { 1,1 });
void setTarget(tankPlayer &p, tankRobot &r)
{
    if(r.pos.X<p.pos.X) r.pos.X++;
    else r.pos.X--;
    if(r.pos.Y<p.pos.Y) r.pos.Y++;
    else r.pos.Y--;
}
int main()
{
    getch();
	int x = 30, y = 30;
	map.renderMap();
	tankPlayer pTank;
	tankRobot rTankTeam[100];
	while (1) {
		pTank.drawConsoleTank();
		for(int i=0;i<3;i++) {rTankTeam[i].drawConsoleTank(i+5,pTank);}
	}
}
