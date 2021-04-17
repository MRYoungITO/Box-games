#pragma once
#ifndef _BOXMAN_H_
#define _BOXMAN_H_

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

#define START_X 100
#define START_Y 150

typedef enum _PROPS			PROPS;
typedef enum _DIRECTION	DIRECTION;
typedef struct _POS				POS;
typedef int								int32;

#define isValid(pos) pos.x >= 0 && pos.x < LINE && pos.y >= 0 && pos.y < COLUMN

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

#endif // !_BOXMAN_H_