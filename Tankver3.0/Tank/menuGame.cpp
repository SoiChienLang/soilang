#include "menuGame.h"
#include<iostream>
#include<string>
using namespace std;
void menuGame(string &mode)
{
    menu m1(1,"New Game");
    menu m2(1," Option");
    menu m3(1,"About me");
    menu m4(1,"  Quit");
    SHORT status[4]={1,0,0,0};
    SHORT index=0;
	fflush(stdin);
    while(1){
        if(GetAsyncKeyState(VK_UP)){index==0?index=3:index--;}
        else if(GetAsyncKeyState(VK_DOWN)){index==3?index=0:index++;}

        for(SHORT i=0;i<4;i++) {if(i==index) status[i]=1;else status[i]=0;}
        m1.status=status[0];m2.status=status[1];m3.status=status[2];m4.status=status[3];
		COORD _p = {62, 2};
        m1.renderMode(70,8,_p);
		_p.Y = 12;
        m2.renderMode(70,8,_p);
		_p.Y = 22;
        m3.renderMode(70,8,_p);
		_p.Y = 32;
        m4.renderMode(70,8,_p);
        if(GetAsyncKeyState(13)) {
            if(index==0){mode="newgame";}
            else if(index==1){mode="option";}
            else if(index==2){mode="aboutme";}
            else {mode="quit";}
            return;
        }
        Sleep(100);
		_getch();
    }
    _getch();
}
menu::menu(SHORT _status,string _mode)
{
    mode=_mode;
    status=_status;
}
void menu::renderMode(SHORT xScreenSize,SHORT yScreenSize,const COORD origin)
{
    HANDLE outConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD garbage = 0;
    COORD pos;pos.X=origin.X;SHORT yPosScreen = yScreenSize + origin.Y;
	COORD p = {origin.X-1,origin.Y-1};
    FillConsoleOutputCharacter(outConsole, 42, xScreenSize+2, p, &garbage);
    FillConsoleOutputAttribute(outConsole, 13, xScreenSize+2, p, &garbage);
	p.X = origin.X, p.Y =origin.Y+yScreenSize;
    FillConsoleOutputCharacter(outConsole, 42, xScreenSize, p, &garbage);
    FillConsoleOutputAttribute(outConsole, 13, xScreenSize, p, &garbage);

    for(SHORT i=0;i<yScreenSize+1;i++){
		p.X = origin.X-1,p.Y = origin.Y+i;
        FillConsoleOutputCharacter(outConsole, 42, 1, p, &garbage);
        FillConsoleOutputAttribute(outConsole, 13, 1, p, &garbage);
		p.X = origin.X+xScreenSize, p.Y = origin.Y+i;
        FillConsoleOutputCharacter(outConsole, 42, 1, p, &garbage);
        FillConsoleOutputAttribute(outConsole, 13, 1, p, &garbage);
    }
    for (pos.Y = origin.Y; pos.Y < yPosScreen; pos.Y++)
	{
		FillConsoleOutputCharacter(outConsole, 176, xScreenSize, pos, &garbage);
		FillConsoleOutputAttribute(outConsole, 3, xScreenSize, pos, &garbage);
	}
    string word[27][MAX];
    install(word);
    reset(word);
    display(mode,word,status,origin);
}

void install(string word[][MAX])
{
	word[0][0]+="        ";
	word[0][1]+="  0000  ";
	word[0][2]+=" 0    0 ";
	word[0][3]+="   0000 ";
	word[0][4]+=" 0    0 ";
	word[0][5]+="  00000 ";

	word[1][0]+=" 0      ";
	word[1][1]+=" 0      ";
	word[1][2]+=" 0 000  ";
	word[1][3]+=" 00   0 ";
	word[1][4]+=" 0    0 ";
	word[1][5]+=" 00000  ";

	word[2][2]+=" 000000 ";
	word[2][1]+=" 0      ";
	word[2][2]+=" 0      ";
	word[2][3]+=" 0      ";
	word[2][4]+=" 0      ";
	word[2][5]+=" 000000 ";

	word[3][0]+=" 00000  ";
	word[3][1]+=" 0    0 ";
	word[3][2]+=" 0    0 ";
	word[3][3]+=" 0    0 ";
	word[3][4]+=" 0    0 ";
	word[3][5]+=" 00000  ";

	word[4][0]+="        ";
	word[4][1]+="  0000  ";
	word[4][2]+=" 0    0 ";
	word[4][3]+=" 0 000  ";
	word[4][4]+=" 0      ";
	word[4][5]+="  0000  ";

	word[5][0]+=" 000000 ";
	word[5][1]+=" 0      ";
	word[5][2]+=" 000000 ";
	word[5][3]+=" 0      ";
	word[5][4]+=" 0      ";
	word[5][5]+=" 0      ";

	word[6][0]+="        ";
	word[6][1]+="  0000  ";
	word[6][2]+=" 0      ";
	word[6][3]+=" 0  000 ";
	word[6][4]+=" 0    0 ";
	word[6][5]+="  0000  ";

	word[7][0]+=" 0    0 ";
	word[7][1]+=" 0    0 ";
	word[7][2]+=" 000000 ";
	word[7][3]+=" 0    0 ";
	word[7][4]+=" 0    0 ";
	word[7][5]+=" 0    0 ";

	word[8][0]+="        ";
	word[8][1]+="   0    ";
	word[8][2]+="   0    ";
	word[8][3]+="   0    ";
	word[8][4]+="   0    ";
	word[8][5]+="   0    ";

	word[9][0]+=" 0    0 ";
	word[9][1]+=" 0   0  ";
	word[9][2]+=" 0000   ";
	word[9][3]+=" 0  0   ";
	word[9][4]+=" 0   0  ";
	word[9][5]+=" 0    0 ";

	word[10][0]+=" 0      ";
	word[10][1]+=" 0      ";
	word[10][2]+=" 0      ";
	word[10][3]+=" 0      ";
	word[10][4]+=" 0      ";
	word[10][5]+=" 000000 ";

	word[11][0]+="        ";
	word[11][1]+=" 0    0 ";
	word[11][2]+=" 00  00 ";
	word[11][3]+=" 0 00 0 ";
	word[11][4]+=" 0    0 ";
	word[11][5]+=" 0    0 ";

	word[12][0]+="        ";
	word[12][1]+=" 0    0 ";
	word[12][2]+=" 0 0  0 ";
	word[12][3]+=" 0  0 0 ";
	word[12][4]+=" 0   00 ";
	word[12][5]+=" 0    0 ";

	word[13][0]+="        ";
	word[13][1]+="  0000  ";
	word[13][2]+=" 0    0 ";
	word[13][3]+=" 0    0 ";
	word[13][4]+=" 0    0 ";
	word[13][5]+="  0000  ";

	word[14][0]+="        ";
	word[14][1]+=" 00000  ";
	word[14][2]+=" 0    0 ";
	word[14][3]+=" 00000  ";
	word[14][4]+=" 0      ";
	word[14][5]+=" 0      ";

	word[15][0]+="  0000  ";
	word[15][1]+=" 0    0 ";
	word[15][2]+=" 0    0 ";
	word[15][3]+=" 0  0 0 ";
	word[15][4]+=" 0   00 ";
	word[15][5]+="  0000  ";

	word[16][0]+=" 00000  ";
	word[16][1]+=" 0    0 ";
	word[16][2]+=" 0    0 ";
	word[16][3]+=" 00000  ";
	word[16][4]+=" 0   0  ";
	word[16][5]+=" 0    0 ";

	word[17][0]+="  00000 ";
	word[17][1]+=" 0      ";
	word[17][2]+="  0000  ";
	word[17][3]+="      0 ";
	word[17][4]+="      0 ";
	word[17][5]+=" 00000  ";

	word[18][0]+="        ";
	word[18][1]+=" 00000  ";
	word[18][2]+="   0    ";
	word[18][3]+="   0    ";
	word[18][4]+="   0    ";
	word[18][5]+="   0    ";

	word[19][0]+="        ";
	word[19][1]+=" 0    0 ";
	word[19][2]+=" 0    0 ";
	word[19][3]+=" 0    0 ";
	word[19][4]+=" 0    0 ";
	word[19][5]+="  0000  ";

	word[20][0]+=" 0   0  ";
	word[20][1]+=" 0   0  ";
	word[20][2]+="  0 0   ";
	word[20][3]+="   0    ";
	word[20][4]+="   0    ";
	word[20][5]+="   0    ";

	word[21][0]+="        ";
	word[21][1]+=" 0    0 ";
	word[21][2]+=" 0    0 ";
	word[21][3]+=" 0    0 ";
	word[21][4]+=" 0 00 0 ";
	word[21][5]+="  0  0  ";

	word[22][0]+=" 0    0 ";
	word[22][1]+="  0  0  ";
	word[22][2]+="   00   ";
	word[22][3]+="   00   ";
	word[22][4]+=" 0   0  ";
	word[22][5]+="0     0 ";





	word[23][0]+="        ";
	word[23][1]+="    0   ";
	word[23][2]+="   00   ";
	word[23][3]+="    0   ";
	word[23][4]+="    0   ";
	word[23][5]+="    0   ";

	word[24][0]+="        ";
	word[24][1]+="   00   ";
	word[24][2]+="  0  0  ";
	word[24][3]+="    0   ";
	word[24][4]+="   0    ";
	word[24][5]+="  0000  ";
}
void reset(string word[][MAX])
{
    char c=42;
    for(SHORT i=0;i<25;i++)
    {
        for(SHORT j=0;j<6;j++){
            for(SHORT k=0;k<8;k++){
                if(word[i][j][k]!=' '){word[i][j][k]=c; }
            }
        }
    }
}
SHORT indexWord(char c)
{
	if(c=='a'||c=='A') return 0;
	if(c=='b'||c=='B') return 1;
	if(c=='c'||c=='C') return 2;
	if(c=='d'||c=='D') return 3;
	if(c=='e'||c=='E') return 4;
	if(c=='f'||c=='F') return 5;
	if(c=='g'||c=='G') return 6;
	if(c=='h'||c=='H') return 7;
	if(c=='i'||c=='I') return 8;
	if(c=='k'||c=='K') return 9;
	if(c=='l'||c=='L') return 10;
	if(c=='m'||c=='M') return 11;
	if(c=='n'||c=='N') return 12;
	if(c=='o'||c=='O') return 13;
	if(c=='p'||c=='P') return 14;
	if(c=='q'||c=='Q') return 15;
	if(c=='r'||c=='R') return 16;
	if(c=='s'||c=='S') return 17;
	if(c=='t'||c=='T') return 18;
	if(c=='u'||c=='U') return 19;
	if(c=='v'||c=='V') return 20;
	if(c=='w'||c=='W') return 21;
	if(c=='x'||c=='X') return 22;
	if(c=='y'||c=='Y') return 20;
	if(c==' ') return 25;
	if(c=='1') return 23;
	if(c=='2') return 24;
}

void display(string words,string word[][MAX],SHORT status,COORD origin)
{
	for(SHORT y=0;y<6;y++)
    {
        for(SHORT i=0;i<words.size();i++){
            gotoxy(origin.X+3+i*8,origin.Y+y+1);
            if(status==1){
                TextColor(4);
                cout<< word[indexWord(words[i])][y];
                TextColor(7);
            }
            else if(status==0){
                TextColor(15);
                cout << word[indexWord(words[i])][y];
                TextColor(7);
            }
        }
    }
}
void gotoxy(SHORT x, SHORT y)
{
    static HANDLE h = NULL;
    if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}
void TextColor(SHORT x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

