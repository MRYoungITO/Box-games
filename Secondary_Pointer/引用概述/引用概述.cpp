#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

//��ʽһ, ʹ��ָ��
void swap1(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//��ʽ��, ʹ������
void swap2(int &a, int &b) {
	//int &c;  //������
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void) {
	int x = 10, y = 100;
	swap2(x, y);

	printf("x: %d, y: %d\n", x, y);

	/*
	int a = 666;
	float c = 10.0;

	int &b = a;  //b��a �ı���
	float &d = c;

	//����ֱ�Ӷ���û��ָ��ı���
	int &e = a;

	printf("a: %d, b: %d\n", a, b);

	b = 888;
	printf("a: %d, b: %d\n", a, b);

	printf("a �ĵ�ַ: 0x%p, b �ĵ�ַ: 0x%p\n", &a, &b);
	*/

	system("pause");
	return 0;
}