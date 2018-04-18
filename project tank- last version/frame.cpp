#include"frame.h"
using namespace std;


void frame::add(int mode, short x, short y)
{
    frameClone _fc;
    _fc.mode=mode;
    _fc.pos.X=x;
    _fc.pos.Y=y;
    fr.push_back(_fc);

}
void frame::setClone(int mode,short x,short y,int size)
{
    for(int i=0;i<size;i++)
    for(int j=0;j<3;j++){
        short px=x+j;
        short py=y+i;
        add(mode, px,py);
    }
}
void frame::_setClone(int mode,short x, short y, int size)
{
    for(int i=0;i<2;i++)
    for(int j=0;j<size;j++){
        short px=x+j;
        short py=y+i;
        add(mode, px,py);
    }
}
void frame::setFrame(int &option)
{
    if(option==0)
    {
        for(int i=0;i<=7;i++) setClone(1,1+19*i,1,5);

        for(int i=0;i<=6;i++) {setClone(2,10+20*i,14,4);setClone(2,10+20*i,22,4);setClone(1,10+20*i,18,4);}
        _setClone(2,25,30,30);_setClone(2,25,35,30);setClone(2,22,30,7);setClone(2,55,30,7);
        _setClone(2,90,30,30);_setClone(2,90,35,30);setClone(2,87,30,7);setClone(2,120,30,7);


        _setClone(2,30,50,25); _setClone(2,85,50,25);
        for(int i=0;i<10;i++) {setClone(2,30-i*2,50-i*2,2*i);setClone(2,110+i*2,50-i*2,2*i);}
        setClone(2,40,58,17);_setClone(2,40,58,24);_setClone(2,75,58,24);setClone(2,99,58,17);
        setClone(2,45,62,13);setClone(2,94,62,13);_setClone(2,55,62,40);
        setClone(2,50,65,10);_setClone(2,50,65,35);setClone(2,88,65,10);
    }
    if(option==1)
    {
        for(int i=0;i<6;i++) _setClone(1,65,20+i,20);
        setClone(1,15,10,30);_setClone(1,15,10,50);
        _setClone(1,85,10,40);setClone(1,125,10,32);
        setClone(1,40,25,15);_setClone(1,40,40,60);
        _setClone(1,30,60,90);setClone(1,120,60,10);
        setClone(1,30,55,5);
        _setClone(1,50,51,40);_setClone(1,50,52,40);_setClone(1,50,53,40);
    }
}
void frame::draw()
{
    for(int i=0;i<fr.size();i++){
        if(fr.at(i).mode==1) {
            FillConsoleOutputCharacter(hOut, 8, 1, {fr[i].pos.X,fr[i].pos.Y},&garbage);
            FillConsoleOutputAttribute(hOut, YELLOW*16+BLACK,1, {fr[i].pos.X,fr[i].pos.Y},&garbage);
        }
        else{
            FillConsoleOutputCharacter(hOut, 182,1,{fr[i].pos.X,fr[i].pos.Y},&garbage);
            FillConsoleOutputAttribute(hOut, RED*16+BLACK,1, {fr[i].pos.X,fr[i].pos.Y},&garbage);
        }
    }
}
