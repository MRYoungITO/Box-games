#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int ages[] = {20, 18, 19, 24, 23, 28, 30, 38, 35, 32};
	int len = sizeof(ages) / sizeof(ages[0]);

	int *p = ages;
	printf("��7����Ů������: %d\n", *(p+6));
	printf("*p+6: %d\n", *p+6);  //*ȡֵ����� ���ȼ����� �Ӻ������
	printf("��3����Ů������: %d\n", *(p+2));

	int *p1 = &ages[4];
	printf("�������Ů,��������͵�ַ: %d, 0x%p\n", *p1, p1);
	printf("����ڵ������Ů,���ĺ�һλ������͵�ַ: %d,  0x%p\n", *(p1+1), p1+1);
	printf("����ڵ������Ů,����ǰһλ������͵�ַ: %d,  0x%p\n", *(p1-1), p1-1);

	/*ͨ��ָ���������
	for(int i=0; i<len; i++) {
		printf("%d ", *p++);
	}
	printf("\n");
	*/

	system("pause");
	return 0;
}