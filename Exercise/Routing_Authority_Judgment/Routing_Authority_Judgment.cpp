#include  <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main (void)
{
	string name;
	string pwd;

	cout << "�������˺ţ�";
	cin >> name;

	cout << "���������룺";
	cin >>pwd;

	if (name == "54hk" && pwd == "123456")
	{
		cout << "1.��վ404����" << endl;
		cout << "2.��վ�۸Ĺ���" << endl;
		cout << "3.��վ������¼" << endl;
		cout << "4.DNS����" << endl;
		cout << "5.��������������" << endl;
	}else
	{
		cout << "�û����������" << endl;
	}

	system("pause");
	return 0;
}