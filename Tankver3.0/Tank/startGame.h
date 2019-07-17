#pragma one
#ifndef STARTGAME_H
#define STARTGAME_H


#include<conio.h>
#include<vector>
#include<string>
#include "Map.h"
#include "tankPlayer.h"
#include "tankRobot.h"
#include "bullet.h"
#include "frame.h"
#include "menuGame.h"

static SHORT numberRobot=10;
static SHORT timeRestore =0;
void setRobot(vector<tankRobot> &);
void drawRobot(vector<tankRobot> &, frame &);
void setBullet(vector<bullet> &, tankPlayer &, vector<tankRobot> &);
void controlBullet(vector<bullet> &);
void drawBullet(vector<bullet> &);
void manage(vector<bullet> &,vector<tankRobot> &, frame &);
SHORT gameOver(vector<bullet> &, tankPlayer &);
void printGameOver();
void printNumberRobot();
void printResult();
void printBot();
void startGame(SHORT );
#endif // STARTGAME_H
