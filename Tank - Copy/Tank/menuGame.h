#ifndef MENUGAME_H
#define MENUGAME_H


#include<iostream>
#include<string.h>
#include<windows.h>
#include<conio.h>
using namespace std;
#define MAX 6
void menuGame(string &);
void gotoxy(SHORT , SHORT );
void TextColor(SHORT );
void install(string word[][MAX]);
void reset(string word[][MAX]);
SHORT indexWord(char );
void display(string , string word[][MAX],SHORT ,COORD origin);
class menu
{
public:
    menu(SHORT ,string );
    void renderMode(SHORT, SHORT, COORD );
    SHORT status;
private:
    string mode;
    char word[5][50];
};
#endif // MENUGAME_H
