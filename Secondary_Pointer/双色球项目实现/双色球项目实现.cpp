#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

#define NUM 7

bool statistics(const char *path, int ball_16[], int len);

int main(void) {
	string filename;
	int ball_16[33] = {0};  //һ��Ҫ�ǵó�ʼ��

	cout << "�������ļ���.\n";
	cin >> filename;

	if(statistics(filename.c_str(), ball_16, 33)) {
		cout << "-----------------------" << endl;
		for(int i=0; i<33; i++) {
			cout << "��" << i+1 << "�������: " << ball_16[i] << "��" << endl;
		}
	} else {//ͳ��ʧ��
		cout << "ͳ�Ƴ���" << endl;
	}

	system("pause");
	return 0;
}

bool statistics(const char *path, int ball_16[], int len) {
	int result[NUM];
	ifstream file;
	int i = 0;

	if(!path) {
		cerr << "path is NULL" << endl;
		return false;
	}

	file.open(path);
	if(file.fail()) {
		cerr << "�������ļ�����." << strerror(errno) <<endl;
		return false;
	}

	//�������ļ������ݵ�����, һ�б����ܶ�ȡ7��
	do {
		i = 0;
		for(i=0; i<NUM; i++) {
			file>>result[i];
			if(file.eof()) {
				break;
			}
			if(file.fail()) {
				cerr << "��ȡ�ļ�ʧ��, ԭ��: " << strerror(errno) << endl;
				break;
			}
		}
		if(i==0) break;  //��¼��������

		//��������δ��7��
		if(i<NUM) {
			cerr << "������" << i << "����¼, Ԥ�ڶ�ȡ7��" << endl;
			file.close();
			return false;
		}

		for(i=0; i<NUM; i++) {
			cout << " " << result[i];
		}
		cout << endl;

		//�Զ�������ݽ���ͳ��
		for(i=0; i<NUM-1; i++) {
			int index = *(result+i)-1;

			if(index>=0 && index<len) {
				*(ball_16+index)+=1;	//��һ��д��: (*(ball_16+index))++;
													//*(ball_16+index)+=1;�״������ֵΪ1,��Ϊ�������г�ʼ�������е�����Ԫ�ص�ֵ��Ϊ0
			}
		}
	} while(1);

	file.close();
	return true;
}