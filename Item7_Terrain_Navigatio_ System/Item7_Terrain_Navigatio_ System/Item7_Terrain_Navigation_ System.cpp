#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

#define N 64

bool isPeak(int grid[N][N], int n, int m);

int main(void) {
	int nrows, ncols;
	int map[N][N];
	string filename;
	ifstream file;

	cout << "������ļ���:  ";
	cin >> filename;

	file.open(filename.c_str());
	if(file.fail()) {
		cout << "�ļ����������.\n";
		system("pause");
		exit(1);
	}

	file >> nrows >> ncols;

	if((nrows >N) || (ncols >N)) {
		cout << "�ļ�����̫��.\n";
		system("pause");
		exit(1);
	}

	for(int i=0; i<nrows; i++) {
		for(int j= 0; j<ncols; j++) {
			file >> map[i][j];
		}
	}

	for(int i=1; i<nrows-1; i++) {
		for(int j=1; j<ncols-1; j++) {
			if(isPeak(map, i, j)) {
				cout << "��������:  " << i << "��  " << j << "  ��." << endl;
			}
		}
	}

	system("pause");
	file.close();
	return 0;
}

bool isPeak(int grid[N][N], int r, int c) {
	if((grid[r][c]>grid[r-1][c]) &&
		(grid[r][c]>grid[r+1][c]) &&
		(grid[r][c]>grid[r][c-1]) &&
		(grid[r][c]>grid[r][c+1])) {
			return true;
	} else {
		return false;
	}
}