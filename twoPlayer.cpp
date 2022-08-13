#include "twoPlayer.h"
void twoPlayer() {
	gamePanel();
	RECT p1 = { 480, 80, 640, 200 };
	setbkmode(TRANSPARENT);
	settextcolor(RGB(25, 25, 112));
	drawtext(_T("player1"), &p1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT p2 = { 480, 240, 640, 360 };
	setbkmode(TRANSPARENT);
	settextcolor(RGB(25, 25, 112));
	drawtext(_T("player2"), &p2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT p3 = { 0,0,50,40 };
	setbkmode(TRANSPARENT);
	settextcolor(RGB(139 ,54 ,38));
	drawtext(_T("返回"), &p3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	ExMessage p;
	while (true) {
		p = getmessage(EM_MOUSE);
		switch (p.message) {
		case  WM_LBUTTONDOWN:
			if (480 <= p.x && p.x <= 640 && 0 <= p.y && p.y <= 80) {

				startGame();
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

void startGame() {

	

	int i = 0;
	palyer player = player1;
	ExMessage p;
	int k = 0;
	int jud_cross=0;//判断对局是否结束
	int jud_circle = 0;
	int x_x, y_x;
	int cross[6][2];
	memset(cross, 0, sizeof(cross));
	int cross_index=0;
	int circle[6][2];
	memset(circle, 0, sizeof(circle));
	int circle_index=0;
	int all[9][2];
	memset(all, 0, sizeof(all));
	int all_index = 0;

	bool repeat = false;

	while (i < 9) {



		while (k != 1) {
			p = getmessage(EM_MOUSE);
			switch (p.message) {
			case  WM_LBUTTONDOWN:
				if (60 <= p.x && p.x <= 420 && 60 <= p.y && p.y <= 420) {

					x_x = (p.x - 60) / 120 * 120 + 120;
					y_x = (p.y - 60) / 120 * 120 + 120;

					/*判断是否有重复*/


					repeat = repeat_Test(x_x, y_x, all);
					if (repeat == true) {
						break;
					}
					else if (repeat == false) {
						draw(x_x, y_x, player);
						k = 1;
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

		

		if (repeat == false) {

			all[all_index][0] = x_x;
			all[all_index][1] = y_x;
			all_index++;

			i++;
			if (i % 2 == 1) {
				cross[cross_index][0] = x_x;
				cross[cross_index][1] = y_x;
				player = player2;
				jud_cross = game_jud(cross, 3);
				cross_index++;
			}
			else if (i % 2 == 0) {
				circle[circle_index][0] = x_x;
				circle[circle_index][1] = y_x;
				player = player1;
				jud_circle = game_jud(circle, 3);
				circle_index++;
			}

			if (jud_cross == 1) {
				MessageBox(GetForegroundWindow(), _T("player1胜利"), _T("提示"), 2);
				twoPlayer();
			}
			if (jud_circle == 1) {
				MessageBox(GetForegroundWindow(), _T("player2胜利"), _T("提示"), 2);
				twoPlayer();
			}

			
		}
	}

	if (i ==9) {
		MessageBox(GetForegroundWindow(), _T("游戏结束"), _T("提示"), 2);
		twoPlayer();
	}

}

void draw(int x_x,int y_x,palyer type) {

	
	if (type == player1) {
		
		line(x_x-20, y_x-20, x_x + 20, y_x + 20);
		line(x_x + 20, y_x - 20, x_x - 20, y_x + 20);
	}

	if (type == player2) {
		circle(x_x, y_x, 20);
	}
	
}



  int game_jud(int twoArray[9][2],int num) {

	int i = 0,j;
	int X_number = 1;
	int Y_number = 1;

	int diagonal = 1;

	

	//在同一排或同一列
	while (twoArray[i+1][0] != 0) {
		
		
		int k = 0;//不在同一斜排
		j = i + 1;
		while (twoArray[j][0] != 0) {
			if (twoArray[i][0] == twoArray[j][0]) {
				X_number++;
			}
			if (twoArray[i][1] == twoArray[j][1]) {
				Y_number++;
			}
			k = jud_cross(twoArray, num);

			j++;
		}



		if (X_number >= num || Y_number >= num||k==1) {
			return 1;
		}
		else {
			i++;
		}
		X_number=1;
		Y_number=1;
		diagonal = 1;
		
	}
	 
	//对角线
	
	

	return 0;
}

  boolean repeat_Test(int x, int y, int twoArray[9][2]) {

	  int t;
	  for (t = 0; twoArray[t][0] != 0; t++) {
		  if (x == twoArray[t][0]&&y==twoArray[t][1]) {
			  return true;
		  }
	  }
	  return false;

  }






  //从一堆二维数组中判断对角线存在
  int jud_cross(int twoArray[9][2], int num) {

	
	  //x，y坐标相等的对角线 equal
	  //相加为480 add
	  int equal = 0;
	  int add = 0;

	  int i = 0;
	  for (i = 0; twoArray[i][0] != 0; i++) {
		  if (twoArray[i][0] == twoArray[i][1]) {
			  equal++;
		  }
		  if(twoArray[i][0]+twoArray[i][1]==480){
			  add++;
		  }

	  }
	  if (equal == 3 || add == 3) {
		  return 1;
	  }
	  return 0;
  

  }