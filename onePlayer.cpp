#include "onePlayer.h"
#include <time.h>
void onePlayer() {
	gamePanel();
	RECT p1 = { 480, 80, 640, 200 };
	setbkmode(TRANSPARENT);
	settextcolor(RGB(25, 25, 112));
	drawtext(_T("computer"), &p1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT p2 = { 480, 240, 640, 360 };
	setbkmode(TRANSPARENT);
	settextcolor(RGB(25, 25, 112));
	drawtext(_T("player"), &p2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT p3 = { 0,0,50,40 };
	setbkmode(TRANSPARENT);
	settextcolor(RGB(139, 54, 38));
	drawtext(_T("返回"), &p3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	ExMessage p;
	while (true) {
		p = getmessage(EM_MOUSE);
		switch (p.message) {
		case  WM_LBUTTONDOWN:
			if (480 <= p.x && p.x <= 640 && 0 <= p.y && p.y <= 80) {

				startGame_one();
			}
			else if (480 <= p.x && p.x <= 640 && 400 <= p.y && p.y <= 480) {
				exit(0);
			}
			else if (0 <= p.x && p.x <= 50 && 0 <= p.y && p.y <= 40) {
				mainPanel();
			}
		default:
			break;
		}
	}

}

void startGame_one() {
	srand((unsigned)time(NULL));
	palyerOne play = palyerOne(rand() % 2);
	int i;
	int x = 120, y = 120;

	int allLocate[10][2];
	memset(allLocate, 0, sizeof(allLocate));
	int cross[6][2];
	memset(cross, 0, sizeof(cross));
	int Cross_count = 0;
	int circle[6][2];
	memset(circle, 0, sizeof(circle));
	int Circle_count = 0;

	int count = 9;//

	//所有可能的坐标
	for (i = 0; i < 3; i++) {
		int j;
		for (j = 3*i; j < (i+1)*3; j++) {
			allLocate[j][0] = x;
			allLocate[j][1] = y;
			y = y + 120;
		}
		x = x + 120;
		y = 120;
	}
	//
	int k = 0;
	i = 0;
	ExMessage p;
	while (i < 9) {




		if (play == computer) {
			
			int m= rand() % count;
			int x = allLocate[m][0];
			int y = allLocate[m][1];
			cross[Cross_count][0] = x;
			cross[Cross_count][1] = y;
			line(x - 20, y - 20, x + 20, y + 20);
			line(x + 20, y - 20, x - 20, y + 20);

			int temp[10][2];
			memset(temp, 0, sizeof(temp));
			int j = 0;
			int a = 0;
			for (j = 0; allLocate[j][0] != 0; j++) {
				if (allLocate[j][0] != x || allLocate[j][1] != y) {
					temp[a][0] = allLocate[j][0];
					temp[a][1] = allLocate[j][1];
					a++;

				}
			}
			memcpy(allLocate,temp,  sizeof(allLocate));




			//deleteNum((int **)allLocate, allLocate[k][0],allLocate[k][1]);
			Cross_count++;
			count--;
			i++;
			play = player;
		}
		else {
			while (k != 1) {
				p = getmessage(EM_MOUSE);
				switch (p.message) {
				case  WM_LBUTTONDOWN:
					if (60 <= p.x && p.x <= 420 && 60 <= p.y && p.y <= 420) {

						int x_x = (p.x - 60) / 120 * 120 + 120;
						int y_x = (p.y - 60) / 120 * 120 + 120;

						/*判断是否有重复*/


						bool have = exit_Test(x_x, y_x, allLocate);
						if (have == false) {
							break;
						}
						else if (have == true) {
							circle[Circle_count][0] = x_x;
							circle[Circle_count][0] = y_x;
							draw(x_x, y_x);
							Circle_count++;
							int temp[10][2];
							memset(temp, 0, sizeof(temp));
							int j = 0;
							int a = 0;
							for (j = 0; allLocate[j][0] != 0; j++) {
								if (allLocate[j][0] != x_x || allLocate[j][1] != y_x) {
									temp[a][0] = allLocate[j][0];
									temp[a][1] = allLocate[j][1];
									a++;

								}
							}
							memcpy(allLocate,temp,  sizeof(allLocate));


							//deleteNum((int**)allLocate,x_x,y_x);
							k = 1; 
							play = computer;
							i++;
							count--;
							break;

						}


					}
					else if (480 <= p.x && p.x <= 640 && 400 <= p.y && p.y <= 480) {
						exit(0);
					}
				default:
					break;
				}
			}
			k = 0;

		}







		
		int jud_cross = game_jud(cross, 3);
		int jud_circle = game_jud(circle, 3);
			
		if (jud_cross == 1) {
			MessageBox(GetForegroundWindow(), _T("computer胜利"), _T("提示"), 2);
			onePlayer();
			
		}
		if (jud_circle == 1) {
			MessageBox(GetForegroundWindow(), _T("player胜利"), _T("提示"), 2);
			onePlayer();
		}


		
	}



	MessageBox(GetForegroundWindow(), _T("游戏结束"), _T("提示"), 2);
	onePlayer();
	

}

void draw(int x_x, int y_x) {
		circle(x_x, y_x, 20);
}


 
/*
失败的函数
void deleteNum(int** twoArray, int x, int y) {
	int i = 0;
	int cross[9][2];
	memset(cross, 0, sizeof(cross));
	int k = 0;
	for (i = 0; *(twoArray[i] + 0) != 0; i++) {
		if (*(twoArray[i] + 0) != x && *(twoArray[i] + 1) != y) {
			cross[k][0] = *(twoArray[i] + 0);
			cross[k][1] = *(twoArray[i] + 1);
			k++;
		}
	}

	twoArray =(int**) cross;

}*/

int game_jud_one(int twoArray[9][2], int num) {

	int i = 0, j;
	int X_number = 1;
	int Y_number = 1;

	int diagonal = 1;



	//在同一排或同一列
	while (twoArray[i + 1][0] != 0) {


		int k = 0;//不在同一斜排
		j = i + 1;
		while (twoArray[j][0] != 0) {
			if (twoArray[i][0] == twoArray[j][0]) {
				X_number++;
			}
			if (twoArray[i][1] == twoArray[j][1]) {
				Y_number++;
			}
			k = jud_cross_one(twoArray, num);

			j++;
		}



		if (X_number >= num || Y_number >= num || k == 1) {
			return 1;
		}
		else {
			i++;
		}
		X_number = 1;
		Y_number = 1;
		diagonal = 1;

	}

	//对角线



	return 0;
}

boolean exit_Test(int x, int y, int twoArray[9][2]) {

	int t;
	for (t = 0; twoArray[t][0] != 0; t++) {
		if (x == twoArray[t][0] && y == twoArray[t][1]) {
			return true;
		}
	}
	return false;

}

//从一堆二维数组中判断对角线存在
int jud_cross_one(int twoArray[9][2], int num) {


	//x，y坐标相等的对角线 equal
	//相加为480 add
	int equal = 0;
	int add = 0;

	int i = 0;
	for (i = 0; twoArray[i][0] != 0; i++) {
		if (twoArray[i][0] == twoArray[i][1]) {
			equal++;
		}
		if (twoArray[i][0] + twoArray[i][1] == 480) {
			add++;
		}

	}
	if (equal == 3 || add == 3) {
		return 1;
	}
	return 0;


}