#include<stdio.h>

char mp[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};

int main()
{
	int a;

	printf("#");
	for(int i=0;i<3;i++)
	{
		scanf("%d",&a);
		printf("%c%c",mp[a/13],mp[a%13]);
	}

	return 0;

}
