#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int guizi1 = 888;
	int *guizi2 = &guizi1;		//��ָͨ��
	int **guizi3 = &guizi2;		//����ָ��һ��
	int ***guizi4 = &guizi3;		//����ָ�����
	int ****guizi5 = &guizi4;	//�ļ�ָ������

	printf("����2��ǹ: %d\n", *guizi2);
	printf("����3��ǹ: %d\n", **guizi3);
	printf("����4��ǹ: %d\n", ***guizi4);
	printf("����5��ǹ: %d\n", ****guizi5);

	system("pause");
	return 0;
}