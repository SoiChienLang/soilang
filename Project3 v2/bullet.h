#include "tankPlayer.h"

class bullet
{
public:
	bullet();
	void drawBullet();
	void getPos(tankPlayer t);
private:
	COORD pos;
};
