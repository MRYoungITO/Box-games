#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int age;
	char ch;
	//������һ��ָ��
	//ָ�뱾��Ҳ��һ������
	//������p, ����һ��ָ��, ����ָ��һ������
	//Ҳ����˵: p��ֵ����һ�������ĵ�ַ!  !  !
	int *p;
	char *c;

	//ָ��p ָ����age
	//p��ֵ, ����age�ĵ�ַ
	p = &age;
	c = &ch;
	scanf_s("%d", p);

	printf("age:%d\n", age);

	system("pause");
	return 0;
}