#include <stdio.h>
#include <stdlib.h>

/*----------------<һά���鴫��>----------------*/

/*��ʽһ���ββ�ָ�������С
	���������ʽ���ݲ���, ����Ҫ�ƶ������Ĵ�С,
	��Ϊ��һά���鴫��ʱ, �ββ������ǵĴ�������,
	����ֻ��������Ԫ�صĵ�ַ
*/

void method_1(int arr[], int len) {
	for(int i=0; i<len; i++) {
		printf(" arr[%d]=%d\n", i, arr[i]);
	}
}

//��ʽ����ָ�������С
void mothod_2(int arr[10]) {
	for(int i=0; i<10; i++) {
		printf(" arr[%d]=%d\n", i, arr[i]);
	}
}

//��ʽ����һά���鴫���˻�, ��ָ����н���, ������������Ԫ�صĵ�ַ
void method_3(int *arr, int len) {
	for(int i=0; i<len; i++) {
		printf(" arr[%d]=%d\n", i, arr[i]);
	}
}

/*int main(void) {
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	method_1(arr, 10);
	printf("------�����ķָ���------\n");
	mothod_2(arr);
	printf("------�����ķָ���------\n");
	method_3(arr, 10);

	system("pause");
	return 0;
}*/

/*-----------------<ָ�����鴫��>---------------*/

//��ʽһ��ָ�����鴫��, ������ָ������, ��ָ�������С
void method_4(int *arr[], int len) {
	for(int i=0; i<len; i++) {
		printf(" arr[%d]=%d\n", i, *(arr[i]));
	}
}

//��ʽ����ָ�����鴫��, ������ָ������, ָ�������С
void method_5(int *arr[10]) {
	for(int i=0; i<10; i++) {
		printf(" arr[%d]=%d\n", i, *(arr[i]));
	}
}

//��ʽ������άָ�봫��
//����ȥ��ָ�������������, ������Ԫ�ص�ַ,���������Ԫ������һ��ָ��
//�ͱ�ʾ����ָ��, �ö���ָ�����
void method_6(int **arr, int len) {
	for(int i=0; i<len; i++) {
		printf(" arr[%d]=%d\n", i, *(*(arr+i)));
	}
}

int main(void) {
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *arr_p[10] = {0};
	for(int i=0; i<10; i++) {
		arr_p[i] = &arr[i];
	}
	method_4(arr_p, 10);
	printf("-----------�����ķָ���-----------\n");
	method_5(arr_p);
	printf("-----------�����ķָ���-----------\n");
	method_6(arr_p, 10);

	system("pause");
	return 0;
}