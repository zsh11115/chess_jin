#include "mainPanel.h"
void mainPanel()
{
	initgraph(640, 480);
	setbkcolor(RGB(174, 238, 238));
	// 用背景色清空屏幕
	cleardevice();


	//标题
	fillellipse(220, 20, 420, 100);
	RECT r = { 220, 20, 420, 100 };
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	
	drawtext(_T("井字棋"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	
	//条目
	fillrectangle(270, 160, 370, 230);
	RECT i1 = { 270, 160, 370, 230 };
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	drawtext(_T("双人模式"), &i1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	fillrectangle(270, 280, 370,350 );
	RECT i2 = { 270, 280, 370,350 };
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	drawtext(_T("人机对战模式"), &i2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	clickItem();

}
void clickItem() {
	ExMessage p;
	while (true) {
		p = getmessage(EM_MOUSE);
		switch (p.message) {
		case  WM_LBUTTONDOWN:
			if (270 <= p.x&& p.x <= 370 && 160 <= p.y&& p.y <= 230) {
				
				twoPlayer();
			}
			else if (270 <= p.x && p.x <= 370 && 280 <= p.y&& p.y <= 350) {
				
				onePlayer();
			}
		default:
			break;
		}
	}
	
	
	
}