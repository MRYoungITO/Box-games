#include <iostream>
#include <string>
#include "��ϰ3.h"

using namespace std;

bool find_max_min(int a[], int len, int* max, int* min) {
	if (len < 1) {
		return false;
	}

	*max = a[0];
	*min = a[0];

	for (int i = 1; i < len; i++) {
		if (*max < a[i]) {
			*max = a[i];
		}
		if (*min > a[i]) {
			*min = a[i];
		}
	}
	return true;
}

int main(void) {
	int a[12] = { 3,9,16,4,7,13,5,8,3,6,2 };
	int max = 0, min = 0;

	find_max_min(a, 12, &max, &min);
	cout << "Max: " << max << " Min: " << min << endl;
	
	system("pause");
	return 0;
}