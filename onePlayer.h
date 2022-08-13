#pragma once
#include "main.h"
#include "gamePanel.h"
#include "GameButton.h"
enum palyerOne {
	player, computer
};
void onePlayer();
void startGame_one();
void draw(int x_x, int y_x);
boolean exit_Test(int x, int y, int twoArray[9][2]);
void deleteNum(int** twoArray, int x, int y);
int game_jud_one(int twoArray[9][2], int num);
int jud_cross_one(int twoArray[9][2], int num);