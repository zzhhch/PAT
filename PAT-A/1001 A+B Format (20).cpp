#include<cstdio>

int main()
{
	int a,b,c,i=0;
	int ans[10]={0};
	scanf("%d %d",&a,&b);
	c=a+b;

	if(c<0)
	{
		printf("-");
		c=-c;
	}
	if(c==0)
		ans[i++]=0;
	while(c)
	{
		ans[i++]=c%10;
		c/=10;
	}
	for(int k=i-1;k>=0;k--)
	{
		printf("%d",ans[k]);
		if(k>0&&k%3==0)
			printf(",");
	}

	return 0;

}
