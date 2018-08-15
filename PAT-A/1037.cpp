#include<cstdio>
#include<algorithm>
using namespace std;

int coupon[100010],bonus[100010];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int n,k,sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&coupon[i]);
	}
	scanf("%d",&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&bonus[i]);
	}
	sort(coupon,coupon+n,cmp);
	sort(bonus,bonus+n,cmp);
	int i=0;
	while(coupon[i]>0&&bonus[i]>0&&i<min(n,k))
	{
		sum+=coupon[i]*bonus[i];
		i++;
	}
	int j=n-1,m=k-1;
	while(coupon[j]<0&&bonus[m]<0&&j>=0&&m>=0)
	{
		sum+=coupon[j]*bonus[m];
		j--;
		m--;
	}

	printf("%d",sum);

	return 0;
}