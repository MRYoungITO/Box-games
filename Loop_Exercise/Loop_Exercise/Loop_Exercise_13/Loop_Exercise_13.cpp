#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main(void) {
	char str[256];
	int i = 0;
	
	cout <<"������һ�仰(Ӣ��): ";
	gets_s(str, sizeof(str));

	while(str[i]) {
		//����ǰ��Ŀո�
		//��ѭ��������,str[i]���¸����ʵĵ�һ����ĸ
		while(str[i] == ' ') i++;
		int j = i;
		//��ѭ������֮��, str[j]��������ʺ������һ��λ��
		while(str[j] && str[j] != ' ') j++;
	
		//��ת�������
		for (int k1= i, k2=j-1; k1<k2; k1++, k2--) {
			char tmp = str[k1];
			str[k1] = str[k2];
			str[k2] = tmp;
		}

		i = j;  //��iָ����һ��λ��
	}

	for (int k1= 0, k2=i-1; k1<k2; k1++, k2--) {
			char tmp = str[k1];
			str[k1] = str[k2];
			str[k2] = tmp;
		}

	cout <<str << endl;

	system("pause");
	return 0;
}