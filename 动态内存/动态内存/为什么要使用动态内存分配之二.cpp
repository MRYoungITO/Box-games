#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ͨ�����ض�̬�ڴ��ָ��
int* demo(int count) {
	int* ap = NULL;

	//new delete C++ �Ķ�̬�ڴ���������c ������malloc
	ap = (int*)malloc(sizeof(int) * count);//�����������ڴ���ֽ���
	//ap = new int[count];
	for (int i = 0; i < count; i++) {
		ap[i] = 100 + i;
	}
	for (int i = 0; i < count; i++) {
		printf("*(ap+%d) = %d\n", i, *(ap + i));
	}
	return ap;
}
//ͨ������ָ��������
void demo1(int count, int** pointer_p) {
	int* ap = NULL;
	*pointer_p = (int*)malloc(sizeof(int) * count);
	ap = *pointer_p;
	for (int i = 0; i < count; i++) {
		ap[i] = 100 + i;
	}
	for (int i = 0; i < count; i++) {
		printf("*(ap+%d) = %d\n", i, *(ap + i));
	}
}

int main3(void) {
	//���ַ�ʽ��ȡ�����ú����ڲ����ڴ�
	int* pointer = NULL;
	int count = 10;
	//��һ�֣�ͨ�����ض�̬�ڴ��ָ��
	//pointer = demo(count);
	//�ڶ��֣�ͨ������ָ��������
	demo1(count, &pointer);
	for (int i = 0; i < 10; i++) {
		printf("*(pointer+%d) = %d\n", i, *(pointer + i));
	}
	//�����ˣ�Ҫ�ǵ��ͷ�
	free(pointer); //c �����е��ͷ��ڴ溯�����൱��delete
	system("pause");
	return 0;
}