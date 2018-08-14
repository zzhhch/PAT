#include<cstdio>

int main()
{
	int n,a,b,c,score[1010]={0};
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		scanf("%d-%d %d",&a,&b,&c);
		score[a]+=c;
	}
	int k=0;
	for(int i=1;i<1010;i++)
	{
		if(score[i]>score[k])
			k=i;
	}

	printf("%d %d",k,score[k]);

	return 0;
}