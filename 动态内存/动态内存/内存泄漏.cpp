#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <stdio.h>
#include <Windows.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new (_NORMAL_BLOCK,  __FILE__, __LINE__)
#define new DBG_NEW
#endif
#endif

using namespace std;

void A_live() {
	int*	p = new int[1024];
	//�ӻ�
	p[0] = 0;
	//������ڴ����Ҫ"��"(�ͷ�)
	delete[] p;
}

void B_live() {
	int* p = new int[1024];
	//�����Ŀ�֧
	p[0] = 0;
	delete[] p;
}

int main11(void) {

	for (int i = 0; i < 5; i++) {
		A_live();
		//B_live();
		Sleep(50);
	}

	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}