#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <Windows.h>

using namespace std;

const double THRESHOLD = 1.5;	//THRESHOLD--->��ֵ
//(��ʱ�䴰�����ݵ�ƽ���������ƽ��ֵ / ��ʱ�䴰�����ݵ�ƽ���������ƽ��ֵ = ��ֵ)  �뷧ֵ�Ƚ�

//�����/��ʱ�䴰���������ݵĲ���ֵ
double power_w(double* arr, int length, int n);

int main9(void) {
	string filename;
	ifstream fin;		//fin ������	cin����, �����ļ�����;
	int num = 0, short_window = 0, long_window = 0;	//�����ݵ�������, ��ʱ�䴰��, ��ʱ�䴰�ڷֱ��ʼ��Ϊ0;
	double time_incr = 0, * sensor = NULL, short_power = 0, long_power = 0;	//time_incr��ʱ�������ļ��, ����ÿ��һ�����ݵ�ʱ����;
	//����һ��double����*sensor(������)ָ��,���ڴ洢������������;	//��ʱ�䴰�ڵ�����ֵ, ��ʱ�䴰�ڵ�����ֵ
	double ratio = 0;		//�������, ���� = ��ʱ�䴰������ֵ / ��ʱ�䴰������ֵ

	cout << "Enter name of input file: " << endl;
	cin >> filename;

	fin .open(filename.c_str());
	if (fin.fail()) {
		cerr << "error opening input file!" << endl;
		exit(-1);
	}
	else {
		fin >> num >> time_incr;
		cout << "num: " << num << " time_incr: " << time_incr << endl;

		if (num >= 0) {
			sensor = new double[num];

			for (int i = 0; i < num; i++) {
				fin >> sensor[i];
				//cout << *(sensor+i) << endl;  �����Ƿ�������������
			}

			cout << "Enter number of points for short-window: " << endl;		//�����ʱ���������ڵ�����
			//(��ʱ�䴰�����ݵ�ƽ���������ƽ��ֵ / ��ʱ�䴰�����ݵ�ƽ���������ƽ��ֵ = ��ֵ)
			cin >> short_window;

			cout << "Enter number of points for long-window: " << endl;
			cin >> long_window;

			//������������, �ҳ������¼�
			for (int i = long_window-1; i < num; i++) {
				short_power = power_w(sensor, i, short_window);
				long_power = power_w(sensor, i, long_window);

				ratio = short_power / long_power;

				if (ratio > THRESHOLD) {
					cout << "Possible event at " << time_incr * i << " seconds" << endl;
				}
			}
			delete[] sensor;	//��̬�ڴ������Ϻ�ǵ��ͷŻ���, һ��Ҫ�����ڴ�й©
		}

		fin.close();
	}

	system("pause");
	return 0;
}

//ͳ�ƶ�/��ʱ�䴰�ڶ�Ӧ����ֵ�Ĳ���ֵ
double power_w(double* arr, int length, int n) {
	double xsquare = 0;		//�󵽵�ƽ��ֵ

	for (int i = 0; i < n; i++) {
		xsquare += pow(arr[length-i], 2);		//powʹ����Ҫ����cmathͷ�ļ�;
		//����pow������ʾ����ٴη�, �����е�2��ʾ��2�η�
	}
	return xsquare / n;
}