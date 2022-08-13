#include "gamePanel.h"
void gamePanel()
{
	initgraph(640, 480);
	setbkcolor(WHITE);
	// 用背景色清空屏幕
	cleardevice();

	COLORREF col = RGB(175, 255, 240);
	setfillcolor(col);
	solidrectangle(480, 0, 640, 80);
	solidrectangle(480, 400, 640, 480);

	
	RECT r = { 480, 0, 640, 80 };
	setbkmode(TRANSPARENT);
	settextcolor(RGB(25, 25, 112));
	drawtext(_T("开始"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	RECT t = { 480, 400, 640, 480 };
	setbkmode(TRANSPARENT);
	settextcolor(RGB(25, 25, 112));
	drawtext(_T("退出"), &t, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	COLORREF colo = RGB(175, 175, 255);
	setfillcolor(colo);
	solidrectangle(480, 80, 640, 240);
	solidrectangle(480, 240, 640, 400);

	COLORREF colp = RGB(64, 224, 208);
	setfillcolor(colp);
	solidrectangle(0, 0, 50, 40);
	

	setfillcolor(WHITE);
	solidrectangle(480, 200, 520, 240);
	solidrectangle(480, 360, 520, 400);


	setlinecolor(BLACK);
	line(480, 240, 640, 240);
	line(480, 0, 480, 640);
	line(480, 80, 640, 80);
	line(480, 400, 640, 400);
	line(490, 210, 510, 230);
	line(510, 210, 490, 230);
	circle(500, 380, 10);



	setlinecolor(BLACK);
	line(60, 60, 420, 60);
	line(60, 180, 420, 180);
	line(60, 300, 420, 300);
	line(60, 420, 420, 420);
	line(60, 60, 60, 420);
	line(180, 60, 180, 420);
	line(300, 60, 300, 420);
	line(420 , 60, 420, 420);



}