#include<conio.h>
#include "Map.h"
#include "tankPlayer.h"
#include "tankRobot.h"
#include "bullet.h"
#include<vector>

using namespace std;


void bulletControl(vector<bullet> &b,tankPlayer &t)
{
    if(GetAsyncKeyState(VK_SPACE)) {
        bullet _b;
        _b.getCoord(t);
        b.push_back(_b);
    }
    for(int i=0;i<b.size();i++)
        if(b.at(i).pos.X<=3||b.at(i).pos.X>=163||b.at(i).pos.Y<=3||b.at(i).pos.Y>=40) b.erase(b.begin()+i);
}
void drawBullet(vector<bullet> &b)
{
    for(int i=0;i<b.size();i++)
    b[i].fire();
}

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
    vector<bullet> b;

 	while (1) {
		pTank.drawConsoleTank(frame);
		bulletControl(b,pTank);
		drawBullet(b);
		for(int i=0;i<5;i++) {rTankTeam[i].drawConsoleTank(i+5,frame);}
		renderFrame(frame);
	}
}
