#include<cstdio>

int main()
{
	int n,a,b,c;
	scanf("%d",&n);
	a=n/100;
	b=n%100/10;
	c=n%10;
	for(int i=0;i<a;i++)
		printf("B");
	for(int i=0;i<b;i++)
		printf("S");
	for(int i=1;i<=c;i++)
		printf("%d",i);

	return 0;
}