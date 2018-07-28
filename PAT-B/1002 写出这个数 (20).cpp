#include<cstdio>
#include<cstring>

char mp[][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main()
{
	char n[101];
	int sum=0,answer[10]={0};
	scanf("%s",n);
	int len=strlen(n);

	for(int i=0;i<len;i++)
	{
		sum=sum+(n[i]-'0');
	}
	int count=0;
	do
	{
		answer[count++]=sum%10;
		sum/=10;
	}while(sum);
	for(int i=count-1;i>=0;i--)
	{
		printf("%s",mp[answer[i]]);
		if(i!=0)
			printf(" ");
	}

	return 0;
}