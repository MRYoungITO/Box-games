#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _friend {
	char name[32];
	char sex;		//m - ��   f - Ů
	int age;
};

int main6(void) {
	struct _friend girl = { "С��Ů",'f',18 };
	
	struct _friend* my_girl = &girl;
	//(*my_girl)

	printf("С��Ů������: %s, �Ա�: %s, ����: %d\n", girl.name, girl.sex == 'm' ? "��" : "Ů", girl.age);

	//ָ����ʽṹ������ĳ�Ա, �����ַ�ʽ
	//��ʽһ	ֱ�ӽ���
	printf("С��Ů������: %s, �Ա�: %s, ����: %d\n", (*my_girl).name, (*my_girl).sex == 'm' ? "��" : "Ů", (*my_girl).age);

	//��ʽ��	ֱ��ʹ��ָ�����	->
	printf("С��Ů������: %s, �Ա�: %s, ����: %d\n", my_girl->name, my_girl->sex == 'm' ? "��" : "Ů", my_girl->age);

	system("pause");
	return 0;
}