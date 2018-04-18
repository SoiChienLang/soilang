#pragma one
#ifndef FRAME_H
#define FRAME_H

#include "Map.h"
#define sizeX 9
#define sizeY 5
#define maxX 140-sizeX+1
#define maxY 70
#define minX 1
#define minY 1
using namespace std;
struct frameClone
{
    int mode;
    COORD pos;
};

class frame
{
public:
    void add(int , short , short);
    void setClone(int ,short,short,int );
    void _setClone(int,short, short ,int );
    void setFrame(int &);
    void draw();
    vector<frameClone> fr;
private:
    HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD garbage=0;
};
#endif // FRAME_H
