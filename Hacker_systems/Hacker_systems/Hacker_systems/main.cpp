#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include "hacker.h"


using namespace std;

#define WIDTH 40
#define HEIGHT 15

void init(void) {
	//mode con cols=40 lines=10
	char cmd[128];
	sprintf(cmd, "mode con cols=%d lines=%d", WIDTH, HEIGHT);
	system(cmd);
}

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

void printInMiddle(string msg) {
	int leftSpace = (WIDTH - msg.length()) / 2;
	for (int i=0; i<leftSpace; i++) {
		cout << " ";
	}

	cout << msg << endl;
}

void menuShow(void) {
	/*
	system("cls");
	cout << "1.��վ404����" << std::endl;
	cout << "2.��վ�۸Ĺ���" << std::endl;
	cout << "3.�鿴������¼" << std::endl;
	cout << "4.��վ�����޸�" << std::endl;
	cout << "5.�˳�" << endl;
	*/

	string menu[ ] = {
		"1.��վ404����",
		"2.��վ�۸Ĺ���",
		"3.�鿴������¼",
		"4.��վ�����޸�",
		"5.�˳�"
	};
	 
	int max = 0;
	int menuCount = sizeof(menu) / sizeof(menu[0]);
	for (int i=0; i<menuCount; i++) {
		if (menu[i].length() > max) {
			max = menu[i].length();		
		}
	}

	printInMiddle("---�ڿ͹���ϵͳ---");

	int leftSpace = (WIDTH - max) / 2;
	for (int i=0; i<menuCount; i++) {
		for (int i=0; i<leftSpace; i++) {
			cout << " ";
		}
		cout << menu[i] << endl;
	}
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
	char id[64];  //��վ��ID
	char response[MAXSIZE];  //������, �ӷ��������صĽ��

	system("cls");
	
	//cout << "404����..." << endl;
	//int hk_404(char *id, char *response) ;
	printInMiddle("---��վ404����---");
	printInMiddle("������׼����������վID: ");
	scanf_s("%s", id, sizeof(id));

	cout << "����ִ��404����...";

	//���𹥻�
	hk_404(id, response);
	
	string retStr = UTF8ToGBK(response);
	cout << retStr;

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
	init();
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