#include <stdio.h>

int main()
{
	int A,B,D,sum,i=0;
	int a[32];

	scanf("%d %d %d",&A,&B,&D);

	sum=A+B;
	do
	{
		a[i++]=sum%D;
		sum=sum/D;
	} while (sum!=0);
	
	while(--i!=-1)
	{
		printf("%d",a[i]);
	}
	return 0;
}

