#include <stdio.h>
#include <stdlib.h>

int main(void){
	int room1 = 666;
	int room2 = 888;

	int girl;
	
	//int *select = 0;  //��ָ��,����ֵΪ0��ָ��
	int *select = NULL;  //<-ǿ���Ƽ����ַ�ʽ
	scanf_s("%d", &girl);
	
	if(girl == 666){
		select = &room1;
	}else if(girl == 888){
		select = &room2;
	}

	//printf("select:  0x%p,  room1:  0x%p,  room2:  0x%p\n", select, &room1, &room2);
	if(select == 0) {
		printf("û��ѡ���κη���!\n");
	} else {
		printf("ѡ��ķ����ǣ� %d\n", *select);
	}

	system("pause");
	return 0;
}