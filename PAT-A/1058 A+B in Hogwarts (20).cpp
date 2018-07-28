#include<cstdio>

int main()
{
	int a,b,c,d,e,f;

	scanf("%d.%d.%d %d.%d.%d",&a,&b,&c,&d,&e,&f);
	c=c+f;
	if(c>28)
	{
		c=c%29;
		e+=1;
	}
	b=b+e;
	if(b>16)
	{
		b=b%17;
		d+=1;
	}
	a=a+d;
	printf("%d.%d.%d",a,b,c);

	return 0;
	
}