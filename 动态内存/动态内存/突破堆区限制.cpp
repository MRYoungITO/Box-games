#include <stdlib.h>
#include<stdio.h>
#include<string.h>

//ջ���Ŀռ��С�������Ƶģ�windows ��һ����1M - 2M
void demo() {
	//int a1[102400*2]; //100k*2*4 = 800K
	//int a1[102400*3]; //100k*3*4 = 1200K = 1.2M
	int* a1;
	//���ʹ�öѵĻ���64 λwindows 10 ϵͳ��������2G
	a1 = (int*)malloc((int)(1024 * 1000 * 1000));//����2G
	a1[0] = 0;
	printf("This is a demo.\n");
}

int main(void) {
	printf("--start--\n");
	demo();
	printf("--end--\n");
	system("pause");
	return 0;
}