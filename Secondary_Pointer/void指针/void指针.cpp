#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[] = {1, 2, 3, 4, 5};
	char ch = 'a';
	void *p = arr;  //������һ��void * ���͵�ָ��

	//p++;  //void * ָ�벻���������������

	p = &ch;  //�������Ϳ����Զ�ת����void * ָ��

	//printf("�����һ��Ԫ��: %d\n", *p);
	printf(" p: 0x%p, ch: 0x%p\n", p, &ch);

	char *p1 = (char *)p;

	//ǿ������ת��
	printf("p1ָ����ַ���: %c\n", *p1);

	system("pause");
	return 0;
}