#include<stdio.h>

void Show_Array(int * p,int len) {
	int i = 0;
	//p[i]就是主函数a[i]
	
	for (i = 0; i < len; i++){
		printf("%d ",p[i]);
	}
}

int main(void) {
	int a[5] = { 1,2,3,4,5 };

	/*
	案例一
	printf("%p\n",a + 1);
	printf("%p\n", a + 2);
	printf("%p\n", a + 3);

	printf("%d\n", *(a + 1));
	printf("%d\n", *(a + 2));
	printf("%d\n", *(a + 3));
	*/

	//案例二
	Show_Array(a, 5);//a等价于&a[0]   &a[0]本身就是int *类型

	return 0;
}