#include<stdio.h>

void Show_Array(int * p,int len) {
	int i = 0;
	//p[i]����������a[i]
	
	for (i = 0; i < len; i++){
		printf("%d ",p[i]);
	}
}

int main(void) {
	int a[5] = { 1,2,3,4,5 };

	/*
	����һ
	printf("%p\n",a + 1);
	printf("%p\n", a + 2);
	printf("%p\n", a + 3);

	printf("%d\n", *(a + 1));
	printf("%d\n", *(a + 2));
	printf("%d\n", *(a + 3));
	*/

	//������
	Show_Array(a, 5);//a�ȼ���&a[0]   &a[0]�������int *����

	return 0;
}