#include<stdio.h>

char map[5]={'S','H','C','D','J'};

int main()
{
	int k;
	int start[55],begin[55],end[55];
	scanf("%d",&k);

	for(int i=1;i<55;i++)
		start[i]=i;
	for(int i=1;i<55;i++)
		scanf("%d",&begin[i]);

	for(int i=0;i<k;i++)
	{
		for(int j=1;j<55;j++)
		{
			end[begin[j]]=start[j];
		}
		for(int m=1;m<55;m++)
		{
			start[m]=end[m];
		}
	}
	for(int i=1;i<55;i++)
	{
		printf("%c%d",map[(start[i]-1)/13],(start[i]-1)%13+1);
		if(i!=54)
			printf(" ");
	}

	return 0;
}
