#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

void A_live() {
	int* p = new int[1024];
	//�ӻ�
	p[0] = 0;
	//������ڴ����Ҫ"��"(�ͷ�)
}

void B_live() {
	int* p = new int[1024];
	//�����Ŀ�֧
	p[0] = 0;
	delete[] p;
}

int main6(void) {

	for (int i = 0; i < 100000; i++) {
		//A_live();
		B_live();
		Sleep(50);
	}

	system("pause");
	return 0;
}