#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_int(const void *a, const void *b) {
	//printf("����compare_int ��, ���ɧ��Ŷ!\n");
	int *a1 = (int *) a;
	int *b1 = (int *) b;
	//printf("a �ĵ�ַ: 0x%p, b �ĵ�ַ: 0x%p\n", &a, &b);

	return *a1 - *b1;
}

int compare_char(const void *a, const void *b) {
	//printf("����compare_char ��, ���ɧ��Ŷ!\n");
	char c1 = *((char *) a);
	char c2 = *((char *) b);
	
	if(c1>= 'A' && c1<='Z') c1+=32;
	if(c2>= 'A' && c2<='Z') c2+=32;

	return c1 - c2;
}

int main(void) {
	int x = 10;
	int y = 20;

	//������û�е�ַ?
	//printf("compare_int �ĵ�ַ: 0x%p\n", &compare_int);
	//compare_int(&x, &y);

	//ָ����ָ��Ķ��� �Ѻ��������ƹ���, �Ѻ������ĳ� (*����ָ����)
	int (*fp)(const void *a, const void *b); // f=>function��������˼
	
	/*����ʵ���ҵ�C��UNIX�Ŀ����߲�ͨ��һ����ʽ, ����������UNIX�ƹ���ȴ���õڶ��ַ�ʽ
	ANSI C ���������ַ�ʽ*/
	fp = &compare_int;
	(*fp)(&x, &y);  //��һ��, ����ָͨ������ķ�ʽ���е���, (*fp) ��ͬ��compare_int
	//fp(&x, &y);  //�ڶ���, ֱ�ӵ���
	//int sub = (*fp)(&x, &y);
	//printf("%d\n", sub);

	//qsort �����������������
	int arr[] = {2, 10, 30, 1, 11, 8, 7, 111, 520};
	qsort(arr, sizeof(arr)/sizeof(int), sizeof(int), &compare_int);

	for(int i=0; i<sizeof(arr)/sizeof(int); i++) {
		printf(" %d", arr[i]);
	}

	printf("\n");

	//qsort ���Զ��κ����͵������������
	char arr1[] = {"abcdefghiABCDEFGHI"};
	qsort(arr1, sizeof(arr1)/sizeof(char)-1, sizeof(char), &compare_char);

	for(int i=0; i<sizeof(arr1)/sizeof(char)-1; i++) {
		printf(" %c", arr1[i]);
	}

	printf("\n");

	system("pause");
	return 0;
}