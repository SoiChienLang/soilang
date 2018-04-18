#ifndef MENUGAME_H
#define MENUGAME_H


#include<iostream>
#include<string.h>
#include<windows.h>
#include<conio.h>
using namespace std;
#define MAX 6
void menuGame(string &);
void gotoxy(int , int );
void TextColor(int );
void install(string word[][MAX]);
void reset(string word[][MAX]);
int indexWord(char );
void display(string , string word[][MAX],int ,COORD origin);
class menu
{
public:
    menu(int ,string );
    void renderMode(int, int, COORD );
    int status;
private:
    string mode;
    char word[5][50];
};
#endif // MENUGAME_H
