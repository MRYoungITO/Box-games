#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int room = 2;

	int *p1 = &room;
	int *p2 = p1;//int *p2 = &room;

	printf("room �ĵ�ַ:  0x%p\n", &room);

	printf("p1 �ĵ�ַ:  0x%p\n", &p1);
	printf("p2 �ĵ�ַ:  0x%p\n", &p2);

	printf("room ��ռ�ֽ�: %d\n", sizeof(room));
	printf("p1 ��ռ�ֽ�: %d\n", sizeof(p1));
	printf("p2 ��ռ�ֽ�: %d\n", sizeof(p2));

	system("pause");
	return 0;
}