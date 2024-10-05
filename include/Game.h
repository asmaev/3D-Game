#ifndef _GAME_H_
#define _GAME_H_

#include "Cube.h"
#include "Camera.h"
#include "WorldGenerator.h"
#include "Car.h"
#include "time.h"
#include <string.h>


void drawText(int x,int y,const char* text,float r,float g,float b);
void initGame();
void playing();
void menu();
void gameOver();
void youWin();
void updateGame();
void onKeyDown(unsigned char key, int x, int y);
void onKeyUp(unsigned char key, int x, int y);
void mouseMove(int x, int y);
void mouseClick(int button, int state, int x, int y);

#endif







