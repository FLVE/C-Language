#include<stdio.h>
int main(){
    int arr[] = {99,15,100,888,252};
    int len = sizeof(arr)/sizeof(int);
    int i,*p = arr;
    for(i=0;i< len;i++){
        printf("%d ",*(p+i));
    } 
    printf("\n");
    return 0;
}