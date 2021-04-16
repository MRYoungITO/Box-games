#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <string>
#include <conio.h>

#define RATIO 61

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 768

//�����ϡ��¡����ҿ��Ʒ���. 'q' �˳�
#define KEY_UP			'w'
#define KEY_LEFT		'a'
#define KEY_RIGHT	'd'
#define KEY_DOWN	's'
#define KEY_QUIT		'q'

#define LINE 9
#define COLUMN 12

#define isValid(pos) pos.x >= 0 && pos.x < LINE && pos.y >= 0 && pos.y < COLUMN

#define START_X 100
#define START_Y 150

enum _PROPS {
	WALL,			//ǽ
	FLOOR,		//�ذ�
	BOX_DES,	//����Ŀ�ĵ�
	MAN,			//С��
	BOX,			//����
	HIT,				//��������Ŀ��
	ALL
};

//��Ϸ���Ʒ���
enum _DIRECTION {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

using namespace std;

struct _POS {
	int x;		//С�����ڵĶ�ά�������
	int y;		//С�����ڵĶ�ά�������
};

IMAGE images[ALL];

struct _POS man;	//С���ڶ�ά�����е�λ��

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

/**********************************************************
* �ı���Ϸ��ͼ��ͼ��һ���Ӧ���߲�������ʾ
* ����:
*			line - �����ڵ�ͼ��������±�
*			colum - �����ڵ�ͼ��������±�
*			prop - ���ߵ�����
*����ֵ:	��
*/
void changeMap(struct _POS *pos, enum _PROPS prop) {
	map[pos->x][pos->y] = prop;
	putimage(START_X + pos->y * RATIO, START_Y + pos->x * RATIO, &images[prop]);
}

/**********************************************************
* ʵ����Ϸ�ĸ�����(�ϡ��¡�����) �Ŀ���
* ����:
* direct - ��ǰ������
* ���: ��
**********************************************************/
void gameControl(enum _DIRECTION direct) {
	struct _POS next_pos = man;
	switch (direct) {
	case UP:
		next_pos.x--;
		break;
	case DOWN:
		next_pos.x++;
		break;
	case LEFT:
		next_pos.y--;
		break;
	case RIGHT:
		next_pos.y++;
		break; 
	}
	//��չ��	next_pos.x >= 0 && next_pos.x < LINE && next_pos.y >= 0 && next_pos.y < COLUMN
	if (isValid(next_pos) && map[next_pos.x][next_pos.y] == FLOOR) {
		changeMap(&next_pos, MAN);		//С��ǰ��һ��
		changeMap(&man, FLOOR);					//ԭС��λ�ñ�Ϊ�ذ�
		man = next_pos;													//����ǰС��λ�ø���֮ǰ��С�˱����ľ�λ��
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
	loadimage(&images[HIT], _T("bos.bmp"), RATIO, RATIO, true);

	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < COLUMN; j++) {
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
			}
		Sleep(100);
		} while (quit == false);		//!quit

	system("pause");
	return 0;
}