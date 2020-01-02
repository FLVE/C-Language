#include<stdio.h>
int main(){
    int a = 100,b = 999,temp;
    int *pa = &a,*pb = &b;
    printf("a=%d, b= %d\n", a, b);
    
    /**开始交换**/
    temp = *pa;
    *pa = *pb;
    *pb = temp;
    /**交换结束**/
    printf("a=%d, b= %d\n", a, b);

    return 0;
}