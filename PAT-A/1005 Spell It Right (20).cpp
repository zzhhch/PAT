#include<cstdio>
#include<cstring>

char mp[11][7]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main()
{
	char n[110];
	int sum=0,ans[5]={0},count=0;
	scanf("%s",n);
	int len=strlen(n);

	for(int i=0;i<len;i++)
		sum+=n[i]-'0';

	do
	{
		ans[count++]=sum%10;
		sum/=10;
	}while(sum);
	for(int i=count-1;i>=0;i--)
	{
		printf("%s",mp[ans[i]]);
		if(i!=0)
			printf(" ");
	}

	return 0;
}
