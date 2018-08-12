#include<cstdio>

int main(void)
{
	int n,mp[110]={0},k;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		mp[a]++;
	}
	int m;
	scanf("%d %d",&k,&m);
	printf("%d",mp[m]);
	for(int i=1;i<k;i++)
	{
		scanf("%d",&m);
		printf(" %d",mp[m]);
	}
	return 0;
}