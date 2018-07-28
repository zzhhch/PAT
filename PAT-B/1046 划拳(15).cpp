#include<stdio.h>

int main()
{
	int N,a1,a2,b1,b2;
	int a=0,b=0;
	scanf("%d",&N);

	while(N--)
	{
		scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
		if(a2==a1+b1 && b2!=a2)
			b++;
		if(b2==a1+b1 && a2!=b2)
			a++;
	}

	printf("%d %d",a,b);

	return 0;
}