#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int room = 2;
	int room1 = 3;  //3p

	int *p1 = &room;
	int *p2 = p1;  //int *p2 = &room;

	//1.����(����д)ָ����������ֵ, ��������ͨ�����ķ��ʷ�ʽ��ͬ

	int *p3 = p1;

	printf("room �ĵ�ַ:  0x%p\n", &room);
	printf("p1��ֵ��:  0x%p,  p2��ֵ��:  0x%p\n", p1, p2);
	printf("p3��ֵ��:  0x%p\n", p3);

	p3 = &room1;

	printf("p3��ֵ��:  0x%p,  room1�ĵ�ַ:  0x%p\n", p3, &room1);

	//��16���ƴ�ӡ��ַ,�ѵ�ַ�����޷�����������
	printf("p1��ֵ��:  0x%p\n", p1);  //����1
	printf("p1��ֵ��:  0x%x\n", p1);	//����2
	printf("p1��ֵ��:  0x%X\n", p1);	//����3

	int *girl = &room;   

	//room = 3;

	int x = 0;;
	x = *girl;  //*��һ������������, *girl��ʾ��ȡָ��girl��ָ��ı�����ֵ (��ӷ���), &girl�뵱��room

	printf("x:  %d\n", x);

	*girl = 4;
	printf("room:  %d, *girl:  %d\n", room, *girl);

	system("pause");
	return 0;
}