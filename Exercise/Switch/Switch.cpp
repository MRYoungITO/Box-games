#include <iostream>
#include <Windows.h>

using namespace std;

/*
����һ������
���ڶ�����ͷ
��������ϡ��
�����ģ��ײ�
�����壺����
����������Ϣ
�����գ���Ϣ
*/

int main (void)
{
	int num = 0;

	cout << "���������ڣ�1-7����";
	cin >> num;

	switch (num) {
	case 1:
		cout << "����һ������" << endl;
		break;
	case 2:
		cout << "���ڶ�����ͷ" << endl;
		break;
	case 3:
		cout << "��������ϡ��" << endl;
		break;
	case 4:
		cout << "�����ģ��ײ�" << endl;
		break;
	case 5:
		cout << "�����壺����" << endl;
		break;
	case 6:
	case 7: 
		cout << "���������գ���Ϣ" << endl;
		break;
	default:
		cout << "���������������" << endl;
	}

	/*  if ���д��ʾ��
	if (num == 1) {
		cout << "����һ������" << endl;
	} else if (num == 2) {
		cout << "���ڶ�����ͷ" << endl;
	} else if (num == 3) {
		cout << "��������ϡ��" << endl;
	} else if (num == 4) {
		cout << "�����ģ��ײ�" << endl;
	} else if (num == 5) {
		cout << "�����壺����" << endl;
	} else if ((num ==6) || (num == 7)) {
		cout << "���������գ���Ϣ" << endl;
	} else {
		cout << "���������������" << endl;
	}
	*/

	system("pause");
	return 0;
}