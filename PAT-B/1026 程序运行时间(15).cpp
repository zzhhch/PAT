#include<stdio.h>

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);

	a=b-a;
	a=a+50/100;
	printf("%02d:%02d:%02d",a/3600,(a%3600)/60,a%60);

	return 0;
}