#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main(void) {
	char line[256]; //'\0'����0
	int i =0;				//�����ַ������ַ����飩���±�
	int count = 0;   //���ʼ���

	cout << "������һ�仰��";
	gets_s(line, sizeof(line));

	//����ǰ��������ո�
	while(line[i] == ' ') i++;		//'\0'����0
	while(line[i]) {		            //while(line[i] != '\0)
		//  ���������Ķ���ǿո����
		while(line[i] && line[i] != ' ') i++;
		while(line[i] == ' ') i++;	
		count++;
	}

	cout << "һ����" << count << "������" << endl;
	system("pause");
	return 0;
}