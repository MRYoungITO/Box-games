#include <stdio.h>
#include <iostream>
#include "static_test.h"

using namespace std; 

extern int extern_value;
static int yahuan_xiaoli = 24;	//ȫ�־�̬����
//int yahuan_extern = 30;

//�Ĵ�������
void register_demo() {
	register int j = 0;
	printf("j: %d\n", j);
	printf("&j: 0x%p\n", &j);
	//C++ �� register �ؼ����Ѿ��Ż�, ������Ǵ�ӡ���ĵ�ַ, ���ͱ������ͨ��auto ����
	for (register int i = 0; i < 100; i++) {
		//...
	}

	{
		int k = 100;
		k += j;
	}
	printf("register_demo: %d\n", yahuan_xiaoli);
}

//��̬����
void static_demo() {
	static int girl = 18;	//�ֲ���̬����, ֻ��ʼ��һ��
	int yahuan = 17;

	++girl;
	++yahuan;
	printf("girl: %d, yahuan: %d\n", girl, yahuan);
}

//�ⲿ����
void extern_demo() {
	extern_value++;
	printf("extern_value: %d\n", extern_value);
}

int main7(void) {
	int i = 0;	//C���Ե�auto ���ᱨ��, C++ auto �Ѿ�������
	//register_demo();
	//static_demo();
	//static_demo();
	extern_demo();
	//printf("register_demo: %d\n", yahuan_xiaoli);
	test_extern_static();

	system("pause");
	return 0;
}