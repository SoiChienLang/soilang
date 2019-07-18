#include<conio.h>
#include<vector>
#include<string>
#include "Map.h"
#include "tankPlayer.h"
#include "tankRobot.h"
#include "bullet.h"
#include "frame.h"
#include "menuGame.h"
#include "startGame.h"
#include "option.h"
#include "aboutme.h"
#include<mmsystem.h>
using namespace std;

int main()
{
    PlaySound(TEXT("start.wav"),NULL, SND_ASYNC);
    static SHORT option;
    Label:
    string mode;
    menuGame(mode);
    system("cls");
    if(mode=="quit") return 0;
    else if(mode=="newgame"){
		PlaySound(NULL,NULL,0);
		PlaySound(TEXT("background.wav"),NULL, SND_ASYNC|SND_LOOP);
        startGame(option);
        goto Label;
    }
    else if(mode=="option"){
        print(option);
        system("cls");
        goto Label;
    }
    else if(mode=="aboutme"){
        aboutMe();
//		fireboss();
        system("cls");
        goto Label;
    }
}


