#include <stdlib.h>
#include <iostream>

using namespace std;

//�����������
/*
int main007(void) {
	//��һ�ַ��䶯̬�ڴ治ִ�г�ʼ��
	int* p1 = new int;
	*p1 = 100;

	//�ڶ��ַ��䶯̬�ڴ�ͬʱִ�г�ʼ��
	int* p2 = new int(100);
	//������ malloc ����ֵ�� void *
	int* p3 = (int*)malloc(sizeof(int));

	free(p1);	//�������Ϳ��� new free	���Ի��
	delete p3;//�������Ϳ��� malloc delete	���Ի��
	delete p2;//free(p2);	ͬ��Ч��

	system("pause");
	return 0;
}*/

//�����������
int main5(void) {
	int* p1 = (int*)malloc(sizeof(int)*10);
	//p[0] - p[9]		*(p+9)
	int* p2 = new int[10];

	delete p1;		//free(p1);		���Ի��
	delete[] p2;	// free(p2);	���Ի��

	system("pause");
	return 0;
}