#include<stdio.h>

int main()
{
	long long a,b,pa=0,pb=0;
	int c,d;

	scanf("%lld %d %lld %d",&a,&c,&b,&d);

	while(a!=0)
	{
		if(a%10==c)
			pa=pa*10+c;
		a/=10;
	}
	while(b!==0)
	{
		if(b%10==d)
			pb=pb*10+d;
		b/=10;
	}
	pa=pa+pb;

	printf("%lld",pa);

	return 0;
}