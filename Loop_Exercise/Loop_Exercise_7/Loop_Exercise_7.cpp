#include <iostream>
#include <Windows.h>

using namespace std;

int main(void) {
	int n = 0;
	long long a = 1;
	long long b = 1;
	long long value = 0;

	cout << "������쳲��������еĸ�����";
	cin >> n;

	if (!(n<3)) {
		cout << "1 1 ";
	} else if (n <= 0) {
		cout << "���������0��������" << endl;
		system("pasue");
		return 1;
	} else if (n == 1) {
		cout << "1" << endl;
		system("pause");
		return 0;
	} else if (n == 2) {
		cout << "1 1" << endl;
		system("pause");
		return 0;
	}

	for (int i=3; i<=n; i++) {
		value = a + b;
		//a �� b ǰ��һλ
		a = b;
		b = value;
		cout << value << " ";
	}

	system("pause");
	return 0;
}