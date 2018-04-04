#include<conio.h>
#include "Map.h"
#include "tankPlayer.h"
#include "tankRobot.h"

using namespace std;

Map map(165, 42, { 1,1 });

int main()
{
    int frame[45][200];
    setFrame(frame);
    getch();
	int x = 30, y = 30;
	map.renderMap();
	tankPlayer pTank;
	tankRobot rTankTeam[100];
	for(int i=0;i<4;i++) rTankTeam[i].constructPos(i);
	while (1) {
		pTank.drawConsoleTank(frame);
		for(int i=0;i<5;i++) {rTankTeam[i].drawConsoleTank(i+5,frame);rTankTeam[i].updateLocation(frame);}
		renderFrame(frame);
	}
}
