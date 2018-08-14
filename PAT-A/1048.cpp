#include<cstdio>

int mp[550]={0};

int main()
{
	int n,price,a;
	scanf("%d%d",&n,&price);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		mp[a]++;
	}
	int i=0,j=500;
	bool tcase=false;
	while(i<=j)
	{
		while(mp[i]==0)
			i++;
		while(mp[j]==0)
			j--;
		while(mp[i]>=1&&mp[j]>=1&&i+j>price)
			j--;
		while(mp[i]>=1&&mp[j]>=1&&i+j<price)
			i++;
		if(mp[i]>=1&&mp[j]>=1&&i+j==price&&i!=j)
		{
			tcase=true;
			break;
		}
		if(i==j&&mp[i]>=2&&i+j==price)
		{
			tcase=true;
			break;
		}
		i++;
	}
	if(tcase)
	{
		printf("%d %d",i,j);
	}
	else
		printf("No Solution");

	return 0;
}