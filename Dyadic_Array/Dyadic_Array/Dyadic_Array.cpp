#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

int main(void) {
	//int ages[5][25]; //����һ����ά����
	
	//��ʼ��
	//��һ�ַ�ʽ, ��ʼ����ָ��ÿ�е�ֵ
	int a[3][4] = {
		{1, 2, 3, 4},  //Ҳ����{1,2}ʡ�Ե����л�Ĭ����0
		{5, 6, 7, 8},
		{9, 10, 11 ,12}
	};

	//�ڶ��ַ�ʽ, ��ʼ��ʱ��ͷ��ʼ, ���������
	int a1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int a2[3][4] = {1};  //ֻ��ʼ����һ��,������Ĭ����0
	
	for (int i=0;i<3; i++) {
		for (int j=0; j<4; j++) {
			cout << a[i][j] << " ";  //printf("%d", a[i][j]);  C����д��
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}