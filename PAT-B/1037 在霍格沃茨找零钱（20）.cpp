#include<cstdio>

int main()
{
	int a1,b1,c1,a2,b2,c2;
	scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
	int sum1,sum2;
	sum1=a1*17*29+b1*29+c1;
	sum2=a2*17*29+b2*29+c2;
	sum1=sum2-sum1;
	if(sum1<0)
	{
		sum1=-sum1;
		printf("-");
	}
	printf("%d.%d.%d",sum1/17/29,sum1%(17*29)/29,sum1%29);

	return 0;
}