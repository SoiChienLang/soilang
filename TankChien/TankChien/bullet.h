#pragma one
#ifndef BULLET_H
#define BULLET_H

#include "tankPlayer.h"
#include "tankRobot.h"
using namespace std;
class bullet
{
public:
    bullet();
    void fire();
    void getCoord(tankPlayer &t);
    void getCoordRobot(tankRobot &r);
    void drawConsole();
    void eraseConsole();
    SHORT direct;
    SHORT index;
    COORD pos;
private:

    HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
};
#endif // BULLET_H
