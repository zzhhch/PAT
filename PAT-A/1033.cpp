#include<cstdio>
#include<algorithm>
using namespace std;

struct Gas
{
	double price,dis;
}gas[510],start;

bool cmp(Gas a,Gas b)
{
	if(a.dis!=b.dis)
		return a.dis<b.dis;
	else
		return a.price<b.price;
}
int main()
{
	double tank,sum_dis,per_dis;
	int gas_num;
	scanf("%lf%lf%lf%d",&tank,&sum_dis,&per_dis,&gas_num);
	for(int i=0;i<gas_num;i++)
	{
		scanf("%lf%lf",&gas[i].price,&gas[i].dis);
	}
	sort(gas,gas+gas_num,cmp);
	for(int i=0;i<gas_num;i++)
	{
		printf("%lf %lf\n",gas[i].dis,gas[i].price);
	}
	double run=0,sum_price=0;
	int ans=1;
	start=gas[0];
	while(run<1000)
	{
		if(gas[0].dis>0)
			break;
		while(gas[ans].dis-start.dis<=600&&ans<gas_num)
		{
			if(gas[ans].price<start.price)
			{
				run+=gas[ans].dis-start.dis;
				sum_price+=start.price*(gas[ans].dis-start.dis)/per_dis;
				start=gas[ans];
				ans++;
				printf("%lf %lf\n",sum_price,run);
			}
/*			else if(gas[ans+1].dis-start.dis>600&&ans<gas_num-1)
			{
				run+=gas[ans+1].dis-start.dis;
				sum_price+=start.price*(gas[ans+1].dis-start.dis)/per_dis;
				start=gas[ans+1];
				ans+=2;
				printf("%lf %lf\n",sum_price,run);
			}			
		}
		if(ans==gas_num-1&&1300-gas[ans].dis<=600)
		{
			run=1300;
			sum_price+=gas[ans].price*(1300-gas[ans].dis)/per_dis;
		}
		else if((ans==gas_num-1&&1300-gas[ans].dis>=600)||gas[ans].dis-start.dis>600)
			break;
*/	}
}
	if(run==1300)
	{
		printf("%.2f",sum_price);
	}
	else
	{
		printf("%.2f",run);
	}

	return 0;
}