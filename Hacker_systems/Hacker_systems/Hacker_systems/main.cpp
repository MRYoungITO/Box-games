#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

//  ���ض����ܵĴ���,��װ��һ��"����"[����]
//  �Ժ�, ����Ҫ���������,��ֱ�ӵ����������.

void login(void) {
	string name;
	string pwd;	
	
	while (1) {
		system("cls");

		cout << "�������˺�: ";
		cin >> name;

		cout << "����������: ";
		cin >> pwd;

		if (name == "54hk" && pwd == "123456") {
			break;  //return
		} else {
			system("pause");
			cout << "�û������������!" << endl;
		}
	}
}

void menuShow(void) {
		system("cls");
		cout << "1.��վ404����" << std::endl;
		cout << "2.��վ�۸Ĺ���" << std::endl;
		cout << "3.�鿴������¼" << std::endl;
		cout << "4.��վ�����޸�" << std::endl;
		cout << "5.�˳�" << endl;
}

int menuChoice(void) {
	//���빦�ܱ��
	int n = 0;  //�û�����ı��
	while (1) {
		cout << "��ѡ��: ";
		cin >> n;  //����a
		if (cin.fail()) {
			cin.clear();
			cin.sync();
			cout << "��Ч����, ����������." << endl;
			system("pause");
		} else {
			break;
		}
	}
	
	return n;
}

void attack404(void) {
	system("cls");
	cout << "404����..." << endl;
	system("pause");
}

//  ��վ�۸Ĺ���
void siteEdit(void) {
	system("cls");
	cout << "��վ�۸Ĺ���..." << endl;
	system("pause");
}

void attackRecord(void) {
	system("cls");
	cout << "�鿴������¼..." << endl;
	system("pause");
}

void attackRepair(void) {
	system("cls");
	cout << "�����޸�..." << endl;
	system("pause");
}

int main(void) {
	login(); //ʵ�ֵ�½����

	while(1){
		menuShow();  //��ʾ�˵�ѡ��
		int n = menuChoice();  //ѡ��˵�ѡ��

		switch (n) {  //ʵ�ֶ�Ӧ����
		case 1:
			attack404();
			break;
		case 2:
			siteEdit();
			break;
		case 3:
			attackRecord();
			break;
		case 4:
			attackRepair();
			break;
		case 5:
			return 0;
		default:
			cout << "��Ч����, ����������." << endl;
			break;
		}
	}

	system("pause");
	return 0;
}