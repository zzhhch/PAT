#include<stdio.h>
#include<string>
#include<string.h>
int count[10]={0};

int main()
{

	char n[1010];
	scanf("%s",n);
	int len=strlen(n);
	for(int i=0;i<len;i++)
		count[n[i]-'0']++;

	for(int i=0;i<10;i++)
	{
		if(count[i]!=0)
			printf("%d:%d\n",i,count[i]);
	}

	return 0;
}