#include <iostream>
#include <stdlib.h>

using namespace std;

int* add(int x, int y) {
	int sum = x + y;
	return &sum;
}

//���ض�̬�ڴ����ĵ�ַ
int* add1(int x, int y) {
	int* sum = NULL;
	sum = new int;
	*sum = x + y;
	return sum;
}

//���ؾֲ���̬�����ĵ�ַ
int* add2(int x, int y) {
	static int sum = 0;
	printf("sum: %d\n", sum);
	sum = x + y;
	return &sum;
}

int main(void) {
	int a = 3, b = 5;
	int* sum = NULL;
	//cout << add(a, b) << endl;
	//sum = add(a, b);	//����ʹ���ⲿ�����ֲ������ĵ�ַ		bad(��ֹ��)

	//�����ⲿ������̬�ڴ����ĵ�ַ		ok
	//sum = add1(a, b);
	//cout << *sum << endl;
	//delete sum;

	//�����ⲿ�����ֲ���̬�����ĵ�ַ		ok
	sum = add2(a, b);
	cout << *sum << endl;
	*sum = 88888;
	add2(a, b);

	system("pause");
	return 0;
}