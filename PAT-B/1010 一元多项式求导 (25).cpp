#include<stdio.h>

const int maxn=1000;

int main()
{
	int A[maxn]={0};
	int a,b,num=0;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		A[b]=a;
	}
	A[0]=0;
	for(int i=1;i<maxn;i++)
	{
		A[i-1]=A[i]*i;
		A[i]=0;
		if(A[i-1]!=0)
			num++;
	}
	if(num==0)
	{
		printf("0 0");
	}
	else
	{
		for(int i=maxn;i>=0;i--)
	{
		if(A[i]!=0)
		{
			printf("%d %d",A[i],i);
			num--;
			if(num!=0)
				printf(" ");
		}
	}

	}
	

	return 0;

}