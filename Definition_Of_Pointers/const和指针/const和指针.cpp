#include <stdio.h>
#include <stdlib.h>

//const ָ��
int main(void) {
	int wife = 24;
	int girl = 18;

	printf("wife: %d, 0x%p\n", wife, &wife);

	//��һ��   ������
	int *zha_nan = &wife;
	*zha_nan = 25;
	zha_nan = &girl;
	*zha_nan = 19;

	printf("girl: %d  wife: %d\n", girl, wife);

	//�ڶ���   ֱ����
	//int const *zhi_nan = &wife;  ��һ��д��
	const int *zhi_nan = &wife;
	//*zhi_nan = 26;  //���Է���ָ���ֵ, ���޷�ֱ���޸�ָ���ֵ
	printf("ֱ�����ŵ�����͵�ַ: %d, 0x%p\n", *zhi_nan, zhi_nan);
	zhi_nan = &girl;  //���ַ�ʽ����ͨ������ַ�ķ�ʽ������ָ���ֵ
	printf("ֱ��Ů�ѵ�����͵�ַ: %d, 0x%p\n", *zhi_nan, zhi_nan);

	//������   ů����
	int * const nuan_nan = &wife;
	*nuan_nan = 26;
	printf("ֱ�����ŵ�����͵�ַ: %d, 0x%p\n", *nuan_nan, nuan_nan);
	//nuan_nan = &girl;  //������ָ���ĵ�ַ

	//������   ����ů����
	const int * const super_nuan_nan = &wife;  //������ָ���ĵ�ַ, �����޸�ָ�������ֵ
	//super_nuan_nan = 28;
	//super_nuan_nan = &girl;

	//�ܽ�:  ��const ������(int)��, ������ָ���������, ��˭��, ������˭, ˭�Ͳ��ܱ�

	system("pause");
	return 0;
}