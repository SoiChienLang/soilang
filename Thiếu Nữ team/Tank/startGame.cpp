#include "startGame.h"
#include "boss.h"
#include<thread>
#include<mmsystem.h>
void fireboss();
void setRobot(vector<tankRobot> &r)
{
    for(SHORT i=0; i<7; i++) {
        tankRobot _r;
        _r.setCoord(i);
        r.push_back(_r);
    }
}
void drawRobot(vector <tankRobot> &r,frame &f)
{
    for(SHORT i=0; i<r.size(); i++) {
        r[i].draw(i+5,f);
    }
}

void setBullet(vector<bullet> &b, tankPlayer &p,vector<tankRobot> &r)
{
    if(GetAsyncKeyState(VK_SPACE)) {
//		PlaySound(TEXT("fire.wav"),NULL, SND_ASYNC | SND_NOSTOP);
        bullet _b;
        _b.getCoord(p);
        b.push_back(_b);
    }
    for(SHORT i=0; i<r.size(); i++) {
        r[i].fire();
        if(r[i].status==1) {
            bullet _b;
            _b.getCoordRobot(r[i]);
            b.push_back(_b);
        }
    }
}
void controlBullet(vector<bullet> &b)
{


    for(SHORT i=0; i<b.size(); i++) {
        if(b[i].pos.X<=minX||b[i].pos.X>=maxX+8||b[i].pos.Y<=minY||b[i].pos.Y>=maxY+4) {
            b[i].eraseConsole();
            b.erase(b.begin()+i);
        }
    }
}


void drawBullet(vector<bullet> &b)
{
    for(SHORT i=0; i<b.size(); i++) {
        b[i].fire();
    }
}
void manage(vector<bullet> &b, vector<tankRobot> &r, frame &f)
{

    for(SHORT i=0; i<b.size(); i++) {
        for(SHORT j=0; j<r.size(); j++) {
            if(r[j].checkLocal(b[i].pos.X,b[i].pos.Y)==1) {
                if(b[i].index==1) {
                    b[i].eraseConsole();
                    b.erase(b.begin()+i);
                } else if(b[i].index==0&&numberRobot>r.size()) {
                    r[j].eraseConsole();
                    r.erase(r.begin()+j);
                    b[i].eraseConsole();
                    b.erase(b.begin()+i);
                    tankRobot _r;
                    _r.setCoord(j);
                    r.push_back(_r);
                    numberRobot--;
                } else if(numberRobot<=r.size()) {
                    r[j].eraseConsole();
                    r.erase(r.begin()+j);
                    b[i].eraseConsole();
                    b.erase(b.begin()+i);
                    numberRobot--;
                }

            }
        }
    }
    for(SHORT i=0; i<b.size(); i++) {
        for(SHORT j=0; j<f.fr.size(); j++) {
            if(f.fr[j].pos.X==b[i].pos.X&&f.fr[j].pos.Y==b[i].pos.Y) {
                if(f.fr[j].mode==2) {
                    b[i].eraseConsole();
                    b.erase(b.begin()+i);
                    f.fr.erase(f.fr.begin()+j);
                } else if(f.fr[j].mode==1) {
                    b[i].eraseConsole();
                    b.erase(b.begin()+i);
                }
            }
        }
    }
    for(SHORT i=0; i<b.size(); i++)
        if(b[i].index==1) {
            for(SHORT j=0; j<b.size(); j++)
                if(b[j].index==0) {
                    if(b[i].pos.X==b[j].pos.X&&b[i].pos.Y==b[j].pos.Y) {
                        b[i].eraseConsole();
                        b.erase(b.begin()+i);
                        b[j].eraseConsole();
                        b.erase(b.begin()+j);
                    }
                }
        }
    if(timeRestore==100)
        f.draw();
    timeRestore++;
    timeRestore%=101;
}

void controlBulletBoss(vector<bullet> &b, boss &bos)
{
	for(int i = 0 ; i < b.size() ; i++)
	{
		if(bos.checkLocal(b[i].pos.X, b[i].pos.Y) && b[i].index == 0){
			b.erase(b.begin() + i);
			bos.eraseBlood();
			bos.blood--;
			bos.drawBlood();
		}
	}
	
}

int checkDead(boss &bos, tankPlayer &t)
{
	for(int y = 0 ; y <= sizeY ; y++)
	{
		for(int x = 0 ; x <= sizeX ; x++)
		{
			int px = t.pos.X + x;
			int py = t.pos.Y + y;
			if(bos.checkLocal(px, py) == 1) return 1;
		}
	}
	return 0;
}

void printHeart(int heart)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD garbage = 0;
	COORD _pos;
	_pos.X = 150, _pos.Y = 8;
	FillConsoleOutputCharacter(hOut, 3 , 3 - heart, _pos, &garbage);
	FillConsoleOutputAttribute(hOut, LIGHT_AQUA * 16 + BLACK, 3 - heart, _pos, &garbage);
}

void initHeart()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD garbage = 0;
	COORD _pos;
	_pos.X = 150, _pos.Y = 8;
	FillConsoleOutputCharacter(hOut, 3 , 3, _pos, &garbage);
	FillConsoleOutputAttribute(hOut, LIGHT_RED, 3, _pos, &garbage);
}

SHORT gameOver(vector <bullet> &b, tankPlayer &p)
{
    for(SHORT i=0; i<b.size(); i++) {
        if(p.checkLocal(b[i].pos.X, b[i].pos.Y)==1)
            return 1;
    }
	return 0;
}
void printGameOver()
{
    menu gameover(1,"You Lose");
    menu _gameover(1,"You Win");
    system("cls");
    SHORT i=0;
	COORD p = {40, 17};
    if(numberRobot!=0) {
        numberRobot=10;
        while(1) {
            gameover.status=i;
            gameover.renderMode(70,8, p);
            i=1-i;
            Sleep(500);
            gotoxy(55,27);
            cout<<"Press Enter to return menu";
            if(GetAsyncKeyState(13)) {
                Sleep(100);
                return ;
            }
        }
    } else if(numberRobot==0) {
        numberRobot=10;
        while(1) {
            _gameover.status=i;
            _gameover.renderMode(70,8, p);
            i=1-i;
            Sleep(500);
            gotoxy(55,27);
            cout<<"Press Enter to return menu";
            if(GetAsyncKeyState(13)) {
                Sleep(100);
                return ;
            }
        }
    }
}

void gameOverBoss(boss &b, int heart)
{
	menu gameover(1,"You Lose");
    menu _gameover(1,"You Win");
    system("cls");
    SHORT i=0;
	COORD p = {40, 17};
    if(heart == 0) {
        while(1) {
            gameover.status=i;
            gameover.renderMode(70,8, p);
            i=1-i;
            Sleep(500);
            gotoxy(55,27);
            cout<<"Press Enter to return menu";
            if(GetAsyncKeyState(13)) {
                Sleep(100);
                return ;
            }
        }
    } else if(b.blood < 0) {
        while(1) {
            _gameover.status=i;
            _gameover.renderMode(70,8, p);
            i=1-i;
            Sleep(500);
            gotoxy(55,27);
            cout<<"Press Enter to return menu";
            if(GetAsyncKeyState(13)) {
                Sleep(100);
                return ;
            }
        }
    }
}
void printBot()
{
    HANDLE outConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD garbage=0;
	COORD _p;
	_p.X = 146, _p.Y = 2;
	gotoxy(_p.X, _p.Y);
	cout<< "Number Robot Left";
    for(short i=0; i<numberRobot/2; i++) {
		_p.X = 155;
		_p.Y = 5 + i;
        FillConsoleOutputCharacter(outConsole, 1,1, _p, &garbage);
		_p.X = 156;
        FillConsoleOutputCharacter(outConsole, 1,1, _p, &garbage);
		_p.X = 155;
        FillConsoleOutputAttribute(outConsole, LIGHT_RED*16, 2,_p,&garbage);
    }
}
void printResult()
{
    HANDLE outConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD garbage=0;
	COORD _p;
	_p.X = 151, _p.Y = 8;
    FillConsoleOutputCharacter(outConsole, numberRobot%10+48,1,_p, &garbage);
	_p.X = 150;
    FillConsoleOutputCharacter(outConsole, (numberRobot - numberRobot%10)/10 + 48,1, _p, &garbage);
    static short _num=numberRobot;
    for(short i=0; i<10-numberRobot; i++) {
		COORD _p;
        if(i%2==1){
			_p.X = 155;
			_p.Y = (_num-i + 8 +1)/2;
            FillConsoleOutputCharacter(outConsole, 42,1, _p, &garbage);
			
		}
        else{
			_p.X = 156;
			_p.Y = (_num-i + 8)/2;
            FillConsoleOutputCharacter(outConsole, 42,1, _p, &garbage);
		}
    }
}
void startGame(SHORT option)
{
	COORD pos;
	pos.X = 1, pos.Y = 1;
    Map map(maxX+8, maxY+4, pos);
	pos.X = 145;
	pos.Y = 1;
    Map _map(20,20, pos);
    map.renderMap();
    _map.renderMap();
    printBot();
    frame f;
    f.setFrame(option);
    f.draw();
    tankPlayer p;
    p.drawConsole();
    vector<tankRobot> r;
    setRobot(r);
    Sleep(1000);
    vector<bullet> b;

    while(1) {
        p.draw(f);
        drawRobot(r,f);
        setBullet(b,p,r);
        controlBullet(b);
        drawBullet(b);
        manage(b,r,f);
        if(gameOver(b,p)==1) {
            break;
        }
		if(numberRobot == 0){
			fireboss();
			break;
		}
        printResult();
        Sleep(10);
        if(GetAsyncKeyState(VK_BACK)) return ;
    }
    printGameOver();
}


void fireboss()
{
	int heart =3;
	COORD pos;
	pos.X = 1, pos.Y = 1;
    Map map(maxX+8, maxY+4, pos);
	pos.X = 145;
	pos.Y = 1;
    Map _map(20,20, pos);
    map.renderMap();
    _map.renderMap();
//    printBot();
    frame f;
	f.fr.clear();
    f.draw();
    tankPlayer p;
    p.drawConsole();
    vector<tankRobot> r;
    setRobot(r);
	r.clear();

    vector<bullet> b;
	boss bos;
	bos.drawBlood();
	initHeart();
    while(1) {
        p.draw(f);
        drawRobot(r,f);
        setBullet(b,p,r);
		bos.draw(p);
		
        controlBullet(b);
        drawBullet(b);
        manage(b,r,f);
		if(checkDead(bos, p)) {
			heart --;
			p.pos.X = 70;
			p.pos.Y = 5;
		}
		controlBulletBoss(b, bos);
//        printResult();
		printHeart(heart);
		if(bos.blood < 0 || heart == 0){
			break;
		}
		
        if(GetAsyncKeyState(VK_BACK)) return ;
    }
	gameOverBoss(bos, heart);

}