#include<stdio.h>
const char mp[3]={'W','T','L'};

int main()
{
	float a,b,c,sum;
	int A[3]={0};
	float B[3];
	for(int i=0;i<3;i++)
	{
		scanf("%f %f %f",&a,&b,&c);
		if(a>b&&a>c)
		{
			A[i]=0;
			B[i]=a;
		}
		else if(b>c&&b>a)
		{
			A[i]=1;
			B[i]=b;
		}
		else
		{
			A[i]=2;
			B[i]=c;
		}
	}
	sum=(B[0]*B[1]*B[2]*0.65-1)*2;
	printf("%c %c %c %.2f",mp[A[0]],mp[A[1]],mp[A[2]],sum);

	return 0;
}