#include <iostream>
#include <Windows.h>

using namespace std;

int main(void) {
	int n;
	int ret[32];
	int i = 0;  //��ʾ��Ŷ�����������±�

	cout << "������һ����������";
	cin >> n;

	if(n<0) {
		cout << "��Ҫ����һ����������" << endl;
		system("pause");
		return 1;
	}

	while (n != 0) {
		ret[i] = n % 2;
		n = n / 2;
		i++;
	}

	//������

	for (i--; i>=0; i--) {
		cout <<ret[i];
	}

	cout << endl;

	system("pause");
	return 0;
}