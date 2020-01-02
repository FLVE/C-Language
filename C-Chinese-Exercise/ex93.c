#include<stdio.h>
int main(){
    int a = 15,b = 99,c = 222;
    int *p = &a;
    *p = b;//通过指针变量修改内存上的数据
    c = *p;//通过指针变量获取内存上的数据
    printf("%d, %d, %d, %d\n", a, b, c, *p);
    //                                  99,99,99,99
    return 0;
}