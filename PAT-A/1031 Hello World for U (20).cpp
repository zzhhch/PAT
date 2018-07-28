#include<cstdio>
#include<cstring>

int main()
{
	int n1,n2,n3;
	char Input[85];
	scanf("%s",Input);
	int len=strlen(Input);
	n1=n3=(len+2)/3;
	n2=len+2-n1-n3;
	
	for(int i=0;i<n1-1;i++)
	{
		printf("%c",Input[i]);
		for(int j=0;j<n2-2;j++)
		{
			printf(" ");
		}
		printf("%c\n",Input[len-i-1]);
	}
	for(int i=n1-1;i<=len-n3;i++)
	{
		printf("%c",Input[i]);
	}

	return 0;

}