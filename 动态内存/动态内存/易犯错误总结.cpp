#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void) {
	int* p = new int[18];		//������һ���ڴ�, �ܴ�С18*int;
	p[0] = 0;
	char* p1 = NULL;
	/*
	//... ...
	//... ...
	delete[] p;		//ֻ����һ���ͷ�
	//... ...
	//... ...
	delete[] p;		//������ڴ����ͷ�, ��������쳣
	*/

	//2. ����delete, �ڴ�й©
	/*
	do {

	} while ("1==1");
	*/

	//3.�ͷŵ��ڴ治������ʱ�ĵ�ַ, ���������, ���Խ�ֹ��
	/*
	for (int i = 0; i < 18; i++) {
		cout << *(p++) << endl;
	}
	delete[] p;
	cout << "come here!" << endl;
	*/

	//4.�ͷſ�ָ��
	//... ...
	/*
	if (1==0) {	//�����ļ��ܴ򿪵����
		p1 = new char[2048];
	}
	//... ...
	delete[] p1;
	*/

	//5.�ͷ�һ���ڴ��, �������������е�����
	/*
	delete[] p;
	//...���������...
	p[0] = '\0';		//���Խ�ֹ
	*/

	//6.Խ�����
	/*
	memset(p, 0, sizeof(int) * 18);
	for (int i = 0; i < 18; i++) {
		cout << *(p++) << endl;
	}
	//����
	for (int i = 0; i < 18; i++) {
		cout << *(p++) << endl;
	}
	cout << "come here!" << endl;
	*/

	system("pause");
	return 0;
}