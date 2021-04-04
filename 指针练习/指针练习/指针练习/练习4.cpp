/*************************************************************
*ʵ��һ������, ʹ��ָ�����������ַ���.
* ��������: ����Դ�ַ�����ָ��, Ŀ���ַ�����ָ��.
*************************************************************/

#include <iostream>
#include <stdlib.h>

using namespace std;

bool str_cat(char* dest, int len, const char* src1,const char* src2) {  //catenate��"����,ʹ����"����˼, ���Ժ�����������Ϊ"str_cat"
	int pos = 0;  //pos��¼dest��λ��

	if (!dest || len < 1) {
		return false;
	}

	if (src1) {
		while (*src1 && pos < (len - 1)) {
			*(dest + pos) = *src1;
			pos++;
			src1++;
		}
	}
	if (src2) {
		while (*src2 && pos < len - 1) {
			*(dest + pos) = *src2;
			pos++;
			src2++;
		}
	}
	*(dest + pos) = '\0';
	return true;
}

int main4(void) {
	const char* src1 = "����";
	const char* src2 = "С����";
	char dest[64];

	str_cat(dest, sizeof(dest) / sizeof(char), src1, src2);
	cout << "result: " << dest << endl;

	system("pause");
	return 0;
}

/*
#include <iostream>
#include <string>

using namespace std;

void joint_str(string* str1, string* str2, string* str3) {
	*str3 = *str1 + *str2;
}

int main(void) {
	string str1 = "I know I��m changing, I know I��m changing\n";
	string str2 = "��֪�����ڸı䣬���ɱ�";
	string str3 = "0";

	joint_str(&str1, &str2, &str3);
	cout << str3 << endl;

	system("pause");
	return 0;
}
*/