#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main2(void) {
	int farmer[10] = { 20,22,25,19,18,23,17,28,30,35 };
	int num = 0;
	int* salary = NULL;

	do {
		printf("��Ҫ��Ӷ��ũ������: \n");
		scanf_s("%d", &num);
	} while (num <= 10);	//��ʾ�û���������

	//���������Ķ���18
	salary = new int[num];
	//��һ��, �������
	/*for (int i = 0; i < sizeof(farmer) / sizeof(int); i++) {
		*(salary + i) = *(farmer + i);
	}*/

	//�ڶ���, �ڴ濽��
	memcpy(salary, farmer, sizeof(farmer));

	for (int i = sizeof(farmer) / sizeof(int); i < num; i++) {
		*(salary + i) = 18;		//salary[i]=18;
	}

	for (int i = 0; i < num; i++) {
		printf("��%d��ũ���н��: %d\n", i + 1, salary[i]);
	}

	system("pause");
	return 0;
}