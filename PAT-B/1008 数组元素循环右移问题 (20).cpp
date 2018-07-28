#include<stdio.h>

int main()
{
	int N,M,A[110];
	int count=0;

	scanf("%d %d",&N,&M);
	M=M%N;

	for(int i=0;i<N;i++)
	{
		scanf("%d",A[i]);
	}
	for(int i=N-M;i<N;i++)
	{
		printf("%d",A[i]);
		count++;
		if(count<N)
			printf(" ");
	}
	for(int i=0;i<N-M;i++)
	{
		printf("%d",A[i]);
		count++;
		if(count<N)
			printf(" ");
	}

	return 0;
} 
