#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <Windows.h>

using namespace std;

#define N 64

bool isPeak(const double grid[N][N], int r, int c);
bool isValley(const double grid[N][N], int r, int c);
void extremes(const double grid[N][N], int row, int column);

int main(void) {
	int nrows, ncols;
	double map[N][N];
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

	//�������ļ������ݵ�����
	for(int i=0; i<nrows; i++) {
		for(int j=0; j<ncols; j++) {
			file >> map[i][j];
		}
	}
	
	int count= 0;  //int total_peaks = 0;
	//�жϲ���ӡ��ֵλ��
	for(int i=1; i<nrows-1; i++) {
		for(int j=1; j<ncols-1; j++) {
			if(isPeak(map, i, j)) {
				count++;
				cout << "��������:  " << i+1  << "��  " << j+1  << "  ��." << endl;
			}
		}
	}
	cout << "һ����" << count << "�����.\n" << endl;

	int count1 = 0;
	for(int i=1; i<=nrows-1; i++) {
		for(int j=1; j<=ncols-1; j++) {
			if(isValley(map, i, j)) {
				count1++;
				cout << "��ȳ�����:  " << i+1 << "��  " << j+1 << "  ��." << endl;
			}
		}
	}
	cout << "һ����" << count1 << "���ȵ�.\n" << endl;

	//��ӡ���ε����ֵ����Сֵ,�Լ��������ڵ�λ��
	extremes(map, nrows, ncols);

	system("pause");
	file.close();
	return 0;
}

bool isPeak(const double grid[N][N], int r, int c) {
	assert(0<r && r<N-1);
	assert(0<c && c<N-1);`

	if((grid[r][c]>grid[r-1][c-1]) &&  //��ǰԪ�ص���һ��
		(grid[r][c]>grid[r-1][c]) &&		//��ǰԪ�ص���һ��
		(grid[r][c]>grid[r-1][c+1]) &&//��ǰԪ�ص���һ�� 
		(grid[r][c]>grid[r][c-1]) &&		//��ǰԪ�ص�������
		(grid[r][c]>grid[r][c+1]) &&	//��ǰԪ�ص�������
		(grid[r][c]>grid[r+1][c-1]) &&//��ǰԪ�ص���һ��
		(grid[r][c]>grid[r+1][c]) &&	//��ǰԪ�ص���һ��
		(grid[r][c]>grid[r+1][c+1])) {	//��ǰԪ�ص���һ��
			return true;
	} else {
		return false;
	}
}

bool isValley(const double grid[N][N], int r, int c) {
	assert(0<r && r<N-1);
	assert(0<c && c<N-1);

	if((grid[r][c]<grid[r-1][c]) &&
		(grid[r][c]<grid[r+1][c]) &&
		(grid[r][c]<grid[r][c-1]) &&
		(grid[r][c]<grid[r][c+1])) {
			return true;
	} else {
		return false;
	}
}

void extremes(const double grid[N][N], int row, int column) {
	assert(0<=row && row<N);
	assert(0<=column && column<N);

	int pos[2][2]={0};  //pos[0][0] pos[0][1] ������ߵ������  pso[1][0] pos[1][1] ������͵������

	double max = grid[0][0];
	double min = grid[0][0];
	for(int i=0; i<row; i++) {
		for(int j=0; j<column; j++) {
			if(max<grid[i][j]) {
				max = grid[i][j];
				pos[0][0] = i;
				pos[0][1] = j;
			}

			if(min>grid[i][j]) {
				min = grid[i][j];
				pos[1][0] = i;
				pos[1][1] = j;
			}
		}
	}
	printf("���ε����ֵ��λ����:  %lf, %d��, %d��.\n", max, pos[0][0] + 1, pos[0][1] + 1);

	printf("���ε���Сֵ��λ����:  %lf, %d��, %d��.\n", min, pos[1][0] + 1, pos[1][1] + 1);
}