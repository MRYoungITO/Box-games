#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int girls[4][3] = {{173, 158, 166},
							 {168, 155, 171},
							 {163, 164, 165},
							 {163, 164, 172}};
	//int x1,y1,   x2,y2;
	int *qishou[2];  //����һ��������Ԫ�ص�ָ������, ÿ��Ԫ�ض���һ��ָ�����

	if(girls[0][0]>girls[0][1]) {
		qishou[0] = &girls[0][0];
		qishou[1] = &girls[0][1];
	} else {
		qishou[0] = &girls[0][1];
		qishou[1] = &girls[0][0];
	}

	for(int i=2; i<12; i++) {
		//girls[i/3][i%3];
		if(*qishou[1]>=girls[i/3][i%3]) {
			continue;
		}
			//��ѡ�߸��ڵڶ�λ���ֺ�ѡŮ��
			//1.��ѡ�߱ȵ�һλ��ѡ�˰�
		if(girls[i/3][i%3]<=*qishou[0]){
			qishou[1] = &girls[i/3][i%3];
		} else {
			//2.��ѡ�߱�"�ھ�"��
			qishou[1] = qishou[0];
			qishou[0] = &girls[i/3][i%3];
		}
	}

	printf("���Ů�������: %d, �θ�Ů�������: %d\n", *qishou[0], *qishou[1]);

	system("pause");
	return 0;
}