#include<cstdio>
#include<cstring>
#include<algorithm>

char mp[5]={'J','Q','K'};

using namespace std;
int main()
{
	char a[110],b[110];
	int temp=0;

	scanf("%s %s",a,b);
	int len1=strlen(a);
	int len2=strlen(b);
	int len=min(len1,len2);

	for(int i=0,j=1;i<len1;i++)
	{
		if(j%2==0)
		{
			temp=b[len2-j]-a[len1-j];
			if(temp<0)
				temp+=10;
			b[len2-j]=temp+'0';
		}
		else
		{
			temp=(b[len2-j]-'0'+a[len1-j]-'0')%13;
			if(temp>9)
				b[len2-j]=mp[temp-10];
			else
				b[len2-j]=temp+'0';
		}
		j++;
	}
	for(int i=0;i<len2;i++)
	{
		printf("%c",b[i]);
	}

	return 0;
}
