#include <stdio.h>
#include <stdlib.h>

/**
 *  (1)ʹ��"ָ��-ָ��"�ķ�ʽ������������Ԫ�ص�ƫ��ֵ;
 *  (2)ʹ��"ָ��-ָ��"�ķ�ʽ�����ַ���Ԫ�ص�ƫ��ֵ;
 */

int main(void) {
	int ages[] = {20, 18, 19, 24, 23, 28, 30, 38, 35, 32};
	int ages1[] = {18, 19, 20, 22};
	int len = sizeof(ages) / sizeof(ages[0]);

	int *martin = ages+6;
	int *rock = ages+9;

	printf("rock - martin: %d\n", rock-martin);
	printf("martin - rock: %d\n", martin-rock);

	martin = ages+6;
	rock = ages1+3;

	printf("martin: 0x%p, rock: 0x%p, rock-martin: %d\n", martin, rock, rock-martin);

	system("pause");
	return 0;
}