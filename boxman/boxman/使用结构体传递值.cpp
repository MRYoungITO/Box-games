#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct programer {
	char name[32];
	int age;
	int salary;
};

//�β�ʹ�ýṹ��ָ��, ֵ����
struct programer add_salary(struct programer p, int num) {
	p.salary += num;
	return p;
}

//�β�ʹ�ýṹ��ָ��
struct programer* add_salary1(struct programer* p, int num) {
	p->salary += num;
	return p;
}

//�β�ʹ�ýṹ������
struct programer add_salary2(struct programer &p, int num) {
	p.salary += num;
	return p;
}

//�β��ǽṹ�����, ֵ����, ��������
struct programer& add_salary3(struct programer p, int num) {
	p.salary += num;
	return p;
}

int main7(void) {
	struct programer xiaoniu;
	struct programer* p = &xiaoniu;
	strcpy_s(xiaoniu.name, "Сţ");
	xiaoniu.age = 28;
	xiaoniu.salary = 20000;

	//�ṹ�������Ϊ������ֵ��ֵ����, ��int �Ȼ�������һ��
	//xiaoniu = add_salary(xiaoniu, 10000);

	//ָ�봫ֵ
	add_salary1(&xiaoniu, 10000);
	printf("����: %s, ����: %d, ��н���нˮ: %d\n", xiaoniu.name, xiaoniu.age, xiaoniu.salary);

	//���ô�ֵ
	//xiaoniu = add_salary2(xiaoniu, 10000);
	//printf("����: %s, ����: %d, ��н���нˮ: %d\n", xiaoniu.name, xiaoniu.age, xiaoniu.salary);

	//��������
	//xiaoniu = add_salary3(xiaoniu, 20000);
	//printf("����: %s, ����: %d, ��н���нˮ: %d\n", xiaoniu.name, xiaoniu.age, xiaoniu.salary);

	system("pause");
	return 0;
}