#include<stdio.h>

int main()
{
	int a1=0,a2=0,a3=0,a5=0,a_2=0;
	float a4=0;

	int n;
	scanf("%d",&n);
	while(n--)
	{
		int temp;
		scanf("%d",&temp);
		if(temp%5==0&&temp%2==0)
			a1=a1+temp;
		else if(temp%5==1)
		{
			     if(a_2%2==0)
				     a2+=temp;
			     else
				     a2-=temp;
			     a_2++;
		}

		else if(temp%5==2)
			      a3++;
		else if(temp%5==3)
			      a4=(a4+temp)/2;
		     else
		     	(temp%5==4&&temp>a5)
			      a5=temp;
	}

	if(a1==0)
		printf("N ");
	else
		printf("%d ",a1);
	if(a_2==0)
		printf("N ");
	else
		printf("%d ",a2);
	if(a3==0)
		printf("N ");
	else
		printf("%d ",a3);
	if(a4==0)
		printf("N ");
	else
		printf("%.1f ",a4);
	if(a5==0)
		printf("N");
	else
		printf("%d",a5);

	return 0;
}