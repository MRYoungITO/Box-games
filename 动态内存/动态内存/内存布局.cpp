#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<Windows.h>

using namespace std;

int laoyezi = 58;
//int girl = 17;

//1. ջ���ڴ�
void say_hello(const char* msg) {  //�����Ĳ����;ֲ����������ջ��
	//int x, y, z;
	if (msg) {
		printf("Hello %s!\n", msg);
	}
	else {
		printf("Who are u?\n");
	}
	printf("��ү�ӽ���: %d��\n", laoyezi);
}

void gui_fang(int jiaren) {
	static int girl = 17;
	if (girl == 17) {
		girl = 18;
	}
	else {
		girl = 16;
	}
	printf("С�����: %d��\n", girl);
}

int main1(void) {
	int num = 100;
	int* salary = NULL;

	//4.�ַ�����
	const char* p = "ͯ��ϱ";
	const char* p1 = "ͯ��ϱ";

	printf("p:0x%p, 0x%p\n", p, p1);
	system("pause");
	exit(0);

	//3. ȫ�ֱ���/��̬����
	printf("��ү�ӽ���: %d��\n", laoyezi);
	gui_fang(0);
	gui_fang(0);
	//printf("С�����: %d��\n", girl);

	//salary = new int(666);

	//2. ��, ��̬�ڴ����
	salary = new int;		//�ڶ������䶯̬�ڴ�
	*salary = 100;
	printf("salary: %d\n", *salary);
	delete salary;		//����ִ�н���ʱ, ���ն�̬�ڴ�
	system("pause");
	exit(0);
	do {
		printf("��Ҫ��Ӷ��ũ������: \n");
		scanf_s("%d", &num);
	} while (num < 0);	//��ʾ�û���������
	
	salary = new int[num];
	for (int i = 0; i < num; i++) {
		*(salary + i) = i + 1;
	}

	for (int i = 0; i < num; i++) {
		printf("\n��%d��ũ���н��: %d\n", i+1, salary[i]);
	}

	printf("\n--------------OVER--------------\n\n");
	delete[] salary;
	//�м�, delete��Ķ�̬�ڴ�, ��ֹ����
	/*for (int i = 0; i < num; i++) {
		printf("\n��%d��ũ���н��: %d\n", i + 1, salary[i]);
	}*/

	//say_hello("ɧ����!!");
	system("pause");
	return 0;
}