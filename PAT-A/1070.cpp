#include<cstdio>
#include<algorithm>
using namespace std;

struct Mooncake
{
	double tons,price,sum_price;
}mc[1010];

bool cmp(Mooncake a,Mooncake b)
{
	return a.price>b.price;
}

int main()
{
	int n;
	double sum=0,num;
	scanf("%d %lf",&n,&num);
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&mc[i].tons);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&mc[i].sum_price);
		mc[i].price=mc[i].sum_price/mc[i].tons;
	}
	sort(mc,mc+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(num>=mc[i].tons)
		{
			sum=sum+mc[i].sum_price;
			num=num-mc[i].tons;
		}
		else
		{
			sum=sum+num*mc[i].price;
			break;
		}
		//printf("%.2f  %d\n",sum,num);
	}
	printf("%.2f\n",sum);

	return 0;
}