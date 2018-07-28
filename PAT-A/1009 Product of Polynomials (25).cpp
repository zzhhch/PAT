#include<stdio.h>


int main()
{
	int k1,k2,a,count=0;
	double b;
	double A[1001]={0},B[1001]={0},C[2001]={0};

	scanf("%d",&k1);
	for(int i=0;i<k1;i++)//当时把i的范围写到了1000 找了半天错误
	{
		scanf("%d %lf",&a,&b);
		A[a]=b;
	}
	scanf("%d",&k2);
	for(int i=0;i<k2;i++)
	{
		scanf("%d %lf",&a,&b);
		B[a]=b;
	}
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++)
		{
			C[i+j]+=A[i]*B[j];
		}
	for(int i=0;i<=2000;i++)
	{
		if(C[i]!=0)
			count++;
	}
	printf("%d",count);
	for(int i=2000;i>=0;i--)
	{
		if(C[i]!=0)
			printf(" %d %.1lf",i,C[i]);
	}

	return 0;
}