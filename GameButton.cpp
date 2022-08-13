#include "GameButton.h"   
void GameButton() {
	ExMessage p;
	while (true) {
		p = getmessage(EM_MOUSE);
		switch (p.message) {
		case  WM_LBUTTONDOWN:
			if (480 <= p.x && p.x <= 640 && 0 <= p.y && p.y <= 80) {


			}
			else if (480 <= p.x && p.x <= 640 && 400 <= p.y && p.y <= 480) {
				exit(0);
			}
		default:
			break;
		}
	}
}