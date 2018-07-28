#include<stdio.h>


int main()
{
	int k1,k2,k3;
	float K1[1001]={0},K2[1001]={0},K3[1001]={0};
	int a,count=0;
	float b;

	scanf("%d",&k1);
	for(int i=0;i<k1;i++)
	{
		scanf("%d%f",&a,&b);
		K1[a]=b;
	}
	scanf("%d",&k2);
	for(int i =0 ;i<k2;i++)
	{
		scanf("%d%f",&a,&b);
		K2[a]=b;
	}
	for(int i=0;i<=1000;i++)
	{
		K3[i]=K1[i]+K2[i];
		if(K3[i]!=0)
			count++;
	}
	printf("%d",count);
	for(int i=1000;i>=0;i--)
	{
		if(K3[i]!=0)
		{
			printf(" %d %.1f",i,K3[i]);
		}
	}
	return 0;
}