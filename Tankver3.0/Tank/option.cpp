#include"option.h"
#include<iostream>
#include<windows.h>
using namespace std;
void print(SHORT &option)
{
    Sleep(100);
    while(1){
        drawOption(option);
        if(GetAsyncKeyState(13)){Sleep(100);return;}
        _getch();
    }
}
void drawOption(SHORT &option)
{
	COORD _ptemp;
    menu option1(0,"  Map 1");
    menu option2(0," Map 2");
    static SHORT i=0;
    option1.status=1-i;
    option2.status=i;
	_ptemp.X = 1;
	_ptemp.Y = 1;
	option1.renderMode(75,40,_ptemp);
	_ptemp.X = 77;
	option2.renderMode(75,40,_ptemp);
    if(GetAsyncKeyState(VK_LEFT)||GetAsyncKeyState(VK_RIGHT)){i=1-i;option =i;Sleep(100);}
}
