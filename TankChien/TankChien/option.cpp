#include"option.h"
#include<iostream>
#include<windows.h>
using namespace std;
void prSHORT(SHORT &option)
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
    menu option1(0,"  Map 1");
    menu option2(0," Map 2");
    static SHORT i=0;
    option1.status=1-i;
    option2.status=i;
    option1.renderMode(75,40,{1,1});
    option2.renderMode(75,40,{77,1});
    if(GetAsyncKeyState(VK_LEFT)||GetAsyncKeyState(VK_RIGHT)){i=1-i;option =i;Sleep(100);}
}
