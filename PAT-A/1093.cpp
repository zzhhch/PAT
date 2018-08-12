#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;

int main()
{
	char input[maxn];
	scanf("%s",input);

	int num[100010],sum=0,len=strlen(input);

	if(input[0]=='P')
		num[0]=1;
	else
		num[0]=0;
	for(int i=1;i<len;i++)
	{
		if(input[i]=='P')
			num[i]=num[i-1]+1;
		else
			num[i]=num[i-1];
	}//忘记了不等于P时候num[i]要等于num[i-1]
	int T_num=0;
	for(int i=len-1;i>=0;i--)
	{
		if(input[i]=='T')
			T_num++;
		else if(input[i]=='A')
			sum=(sum+num[i]*T_num)%1000000007;
	}

	printf("%d\n",sum);

	return 0;
}