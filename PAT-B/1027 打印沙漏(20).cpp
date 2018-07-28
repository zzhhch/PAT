#include<cstdio>
#include<math.h>

int main()
{
	int n,row,left;
	char m;
	scanf("%d %c",&n,&m);

	row=sqrt((n+1)/2);
	left=n-(2*row*row-1);

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<i;j++)
			printf(" ");
		for(int l=0;l<(2*(row-i)-1);l++)
			printf("%c",m);
		printf("\n");
	}
	for(int i=row-2;i>=0;i--)
	{
		for(int j=0;j<i;j++)
			printf(" ");
        for(int l=0;l<(2*(row-i)-1);l++)
			printf("%c",m);
		printf("\n");
	}
	printf("%d",left);

	return 0;
}