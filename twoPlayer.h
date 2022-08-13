#pragma once
#include "main.h"
#include "gamePanel.h"
#include "GameButton.h"
enum palyer {
	player1,player2
};
void twoPlayer();
void startGame();
void draw(int x, int y, palyer type);
int game_jud(int twoArray[3][2],int num);
boolean repeat_Test(int x, int y, int twoArray[9][2]);
int jud_cross(int twoArray[9][2], int num);
