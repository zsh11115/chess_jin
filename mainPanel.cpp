#include "mainPanel.h"
void mainPanel()
{
	initgraph(640, 480);
	setbkcolor(RGB(174, 238, 238));
	// �ñ���ɫ�����Ļ
	cleardevice();


	//����
	fillellipse(220, 20, 420, 100);
	RECT r = { 220, 20, 420, 100 };
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	
	drawtext(_T("������"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	
	//��Ŀ
	fillrectangle(270, 160, 370, 230);
	RECT i1 = { 270, 160, 370, 230 };
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	drawtext(_T("˫��ģʽ"), &i1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	fillrectangle(270, 280, 370,350 );
	RECT i2 = { 270, 280, 370,350 };
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	drawtext(_T("�˻���սģʽ"), &i2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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