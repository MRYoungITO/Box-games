#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a = 10;
	//int &b = a;
	//1.�ñ�����ʼ��������
	const int &b = a;  //ֻ�ܶ�����д, ����ֻ�ܿ�������

	//b = 100;  //���������ñ������ñ��ֻ��, ����ͨ�����öԱ��������޸�
	printf("a: %d\n", a);

	//2.����������ʼ����������
	const int c1 = 10;
	const int &c2 = 10;  //�������C++ ��, ��������������Ķ�������÷����ڴ�, ������һ������
	int c3 = c2;

	//c2 = 100;  //�����޸�

	system("pause");
	return 0;
}