#include <iostream>
#include <Windows.h>

using namespace std;

void scorePrint(int score[ ], int n) {  //�βα�������һ��ָ��
	for (int i=0; i<n; i++) {
		cout << "��" << i+1 << "�ſγ̵ĳɼ�:  " << score[i] << endl;
	}
}

//��ÿ�ſγ̵ĳɼ�,��5��
void scoreAdd(int score[ ], int n, int val=5) {
	for (int i=0; i<n; i++) {
		score[i] += val;
	}
}
 
void test(int a, int b, int c) {
	a += 5;
	b += 5;
	c += 5;
}

int main(void) {
	//				  0x8000
	//						v
	int score[3] = {60, 70, 80};
	//cout  << sizeof(score) << endl;  //12
	scorePrint(score, 3);

	//  ��������Ϊ�����Ĳ���ʱ,��������п����޸���������ֵ
	scoreAdd(score, 3);

	scorePrint(score, 3);

	system("pause");
}