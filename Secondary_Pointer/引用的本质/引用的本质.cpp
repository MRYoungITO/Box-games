#include <stdio.h>
#include <stdlib.h>

/*
int swap1(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
	return 0;
}
*/

int swap2(int * const _a, int * const _b) {
	int t = *_a;
	*_a = *_b;
	*_b = t;
	return 0;
}

int main(void) {
	int x =10;
	int &y = x;
	int z = 1000;
	int w = 10000;

	//y = z;  //y ��û�а취ָ��z��

	printf("x: %d, z: %d, w: %d\n", &x, &z, &w);




	//int &b = a;
	//b��a�ı���, ����C++��������������ʲô����?


	//1. ��˼��: ��ͬһ�ڴ�ռ����ȡ�ü���������?
	//int &c = a;
	//int &d = a;

	//printf("a: %d, b: %d, c: %d, d: %d\n", a, b, c, d);
	
	//2. ������û���Լ��Ŀռ�

	//����: ���ÿ��Զ�����, �������Լ��Ŀռ�, ��ô, ������ʲô?
	//���ϼ������: �������� ��ָ��
	//int &b = a;			int * const b = &a;
	//swap1(z, w);  ����  swap2(&z, &w);	

	//swap1(z, w);
	//printf("z: %d, w: %d\n", z, w);
	swap2(&z, &w);
	printf("z: %d, w: %d\n", z, w);

	system("pause");
	return 0;
}