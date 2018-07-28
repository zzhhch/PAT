#include<stdio.h>

int main()
{
	int t,i=0;
	long long a,b,c,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld %lld",&a,&b,&c);
		i++;
		d=a+b;
		if(a>0&&b>0&&d<0)
			printf("Case #%d: true\n",i);
		else if(a<0&&b<0&&d>=0)//等于0时也是负溢出
			printf("Case #%d: false\n",i);
		else if(d>c)
			printf("Case #%d: true\n",i);
		else
			printf("Case #%d: false\n",i);
	}
	return 0;
}