#include <iostream>
#include <Windows.h>

using namespace std;

int main (void)
{
	int years;
	int days;

	cout << "�����빤�����ޣ�" << endl;
	cin >> years;

	//������5��,��10����٣�����ֻ��1�����
	/*  �߼����д��
	if (years >= 5)
	{
		days = 10;
	}else
	{
		days = 1;
	}
	*/

	days = years >=5 ? 10 : 1;

	cout << "��������" << days << "�죡" << endl;

	system("pause");
	return 0;
}