#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int guizi2 = 888;  //��ǹ�ĵڶ�������
	int *guizi1 = &guizi2;  //��ڶ������ӵ�ַ�ĵ�һ������
	int **liujian = &guizi1;  //���յ�һ�����ӵ�ַ������

	printf("�����򿪵�һ������, ��õڶ������ӵĵ�ַ: 0x%p\n", *liujian);
	printf("guizi2�ĵ�ַ: 0x%p\n", &guizi2);

	int *tmp;
	tmp = *liujian;

	printf("���ʵڶ�����ӵĵ�ַ, �õ�ǹ: %d\n", *tmp);
	printf("����һ����λ�õ�ǹ: %d\n", *(*liujian));  //��д�� **liujian

	system("pause");
	return 0;
}