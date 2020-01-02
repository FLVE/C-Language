
#include<stdio.h>
main()
{
	int i,j,k,a[10],sum=0;
	scanf("%d",&k);
	for(i=0;k>0;i++)
	{
		a[i]=k%10;
		k/=10;
		sum+=a[i];
	}
	printf("%d %d",i,sum);
	
