#include<cstdio>


int main()
{
	char output[85][85];
	int i=0;

	while(scanf("%s",output[i])!=EOF)
	{
		i++;
	}
	for(int j=i-1;j>=0;j--)
	{
		printf("%s",output[j]);
		if(j!=0)
			printf(" ");
	}

	return 0;

}