#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <string>
#include <conio.h>
#include "boxman.h"

IMAGE images[ALL];

POS man;	//С���ڶ�ά�����е�λ��

int map[LINE][COLUMN] = {
	{0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,1,1,1,1,1,1,1,0,0},
	{0,1,4,1,0,2,1,0,2,1,0,0},
	{0,1,0,1,0,1,0,0,1,1,1,0},
	{0,1,0,2,0,1,1,4,1,1,1,0},
	{0,1,1,1,0,3,1,1,1,4,1,0},
	{0,1,2,1,1,4,1,1,1,1,1,0},
	{0,1,0,0,1,0,1,1,0,0,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0}
};

/************************************************************************
* �ж���Ϸ�Ƿ����, �������������Ŀ�ĵ�, �ʹ�����Ϸ���� 
* ����:	��
*����ֵ:	
*			true - ��Ϸ����			false - ��Ϸ����
************************************************************************/
bool isGameOver() {
	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < COLUMN; j++) {
			if (map[i][j] == BOX_DES) {
				return false;
			}
		}
	}
	return true;
}

/************************************************************************
* ��Ϸ��������, �����ͨ�غ���ʾ, 
* ����:
*				bg - ����ͼƬ������ָ��
*����ֵ:	��
************************************************************************/
void gameOverScene(IMAGE *bg) {
	putimage(0, 0, bg);
	settextcolor(WHITE);
	RECT rec = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	settextstyle(20, 0, _T("����"));
	drawtext(_T("��ϲ��~ \n�����ڳ�Ϊ��һ���ϸ�İ�������˾��! "), &rec, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

/**********************************************************
* �ı���Ϸ��ͼ��ͼ��һ���Ӧ���߲�������ʾ
* ����:
*			line - �����ڵ�ͼ��������±�
*			colum - �����ڵ�ͼ��������±�
*			prop - ���ߵ�����
*����ֵ:	��
**********************************************************/
void changeMap(POS *pos, PROPS prop) {
	map[pos->x][pos->y] = prop;
	putimage(START_X + pos->y * RATIO, START_Y + pos->x * RATIO, &images[prop]);
}

/**********************************************************
* ʵ����Ϸ�ĸ�����(�ϡ��¡�����) �Ŀ���
* ����:
* direct - ��ǰ������
* ���: ��
**********************************************************/
void gameControl(DIRECTION direct) {
	POS next_pos = man;
	POS next_next_pos = man;
	switch (direct) {
	case UP:
		next_pos.x--;
		next_next_pos.x -= 2;
		break;
	case DOWN:
		next_pos.x++;
		next_next_pos.x += 2;
		break;
	case LEFT:
		next_pos.y--;
		next_next_pos.y -= 2;
		break;
	case RIGHT:
		next_pos.y++;
		next_next_pos.y += 2;
		break; 
	}
	//��չ��	next_pos.x >= 0 && next_pos.x < LINE && next_pos.y >= 0 && next_pos.y < COLUMN
	if (isValid(next_pos) && map[next_pos.x][next_pos.y] == FLOOR) {		//С�˵�ǰ���ǵذ�
		changeMap(&next_pos, MAN);		//С��ǰ��һ��
		changeMap(&man, FLOOR);			//ԭС��λ�ñ�Ϊ�ذ�
		man = next_pos;								//����ǰС��λ�ø���֮ǰ��С�˱����ľ�λ��
	}
	else if (isValid(next_next_pos) && map[next_pos.x][next_pos.y] == BOX) {	//С�˵�ǰ��������
		//�������, ����ǰ���ǵذ����������Ŀ�ĵ�
		if (map[next_next_pos.x][next_next_pos.y] == FLOOR) {
			changeMap(&next_next_pos, BOX);
			changeMap(&next_pos, MAN);
			changeMap(&man, FLOOR);
			man = next_pos;
		}
		else if (map[next_next_pos.x][next_next_pos.y] == BOX_DES) {
			changeMap(&next_next_pos, HIT);
			changeMap(&next_pos, MAN);
			changeMap(&man, FLOOR);
			man = next_pos;
		}
	}
}

int main(void) {
	IMAGE bg_img;
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	loadimage(&bg_img, _T("blackground.bmp"), 0, 0, true);
	putimage(0, 0, &bg_img);

	loadimage(&images[WALL], _T("wall_right.bmp"), RATIO, RATIO, true);
	loadimage(&images[FLOOR], _T("floor.bmp"), RATIO, RATIO, true);
	loadimage(&images[BOX_DES], _T("des.bmp"), RATIO, RATIO, true);
	loadimage(&images[MAN], _T("man.bmp"), RATIO, RATIO, true);
	loadimage(&images[BOX], _T("box.bmp"), RATIO, RATIO, true);
	loadimage(&images[HIT], _T("box.bmp"), RATIO, RATIO, true);

	for (int32 i = 0; i < LINE; i++) {
		for (int32 j = 0; j < COLUMN; j++) {
			if (map[i][j] == MAN) {
				man.x = i;
				man.y = j;
			}
			putimage(START_X + j * RATIO, START_Y + i * RATIO, &images[map[i][j]]);
		}
	}

	//��Ϸ����
		bool quit = false;
		do {
			if (_kbhit()) {		//��Ұ���
				char ch = _getch();
				if (ch == KEY_UP) {
					gameControl(UP);
				}
				else if (ch == KEY_DOWN) {
					gameControl(DOWN);
				}
				else if (ch == KEY_LEFT) {
					gameControl(LEFT);
				}
				else if (ch == KEY_RIGHT) {
					gameControl(RIGHT);
				}
				else if (ch == KEY_QUIT) {
					quit = true;
				}
				if (isGameOver()) {
					gameOverScene(&bg_img);
					quit = true;
				}
			}
		Sleep(100);
		} while (quit == false);		//!quit
	system("pause");
	//��Ϸ����, �ͷ���Դ
	closegraph();
	return 0;
}