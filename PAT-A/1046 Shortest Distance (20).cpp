#include<stdio.h>

int min(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}
int distance[100010]={0};

int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&distance[i]);
		distance[i]+=distance[i-1];
	}
	scanf("%d",&m);
	int a,b,temp,dis;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		if(a>b)
		{
			temp=a;
			a=b;
			b=temp;
		}
		dis=min(distance[b-1]-distance[a-1],distance[n]-(distance[b-1]-distance[a-1]));
		printf("%d\n",dis);
	}

	return 0;
}