#include "tankPlayer.h"

class bullet
{
public:
    bullet();
    void fire();
    void getCoord(tankPlayer &t);
    void drawConsole();
    void eraseConsole();
    int direct;
    COORD pos;
private:

    HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
};
