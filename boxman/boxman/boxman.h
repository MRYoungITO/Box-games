#pragma once
#ifndef _BOXMAN_H_
#define _BOXMAN_H_

#define RATIO 61
#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 768

//控制上、下、左、右控制方向. 'q' 退出
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
	WALL,			//墙
	FLOOR,		//地板
	BOX_DES,	//箱子目的地
	MAN,			//小人
	BOX,			//箱子
	HIT,				//箱子命中目标
	ALL
};

//游戏控制方向
enum _DIRECTION {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

using namespace std;

struct _POS {
	int x;		//小人所在的二维数组的行
	int y;		//小人所在的二维数组的列
};

#endif // !_BOXMAN_H_