#include <iostream>
#include <Windows.h>

using namespace std;

int main(void) {
	for (int i=1; i<=20; i++) {      //��ʾ��������
		for (int j=1; j<=33; j++) {  //j��ʾĸ������
			int k = 100 - i - j;          //��ʾС������
			if(k%3 == 0 && i*50+j*30+k/3*10 == 1000) {
					cout << "������" << i << " ĸ����" << j << " С����" << k << endl;
			}
		}
	}

	system("pause");
	return 0;
}