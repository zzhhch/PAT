#include<cstdio>
#include<cstring>
using namespace std;

int mp[130]={0};

int main()
{
	char temp,a[10010];
	int k=0;
	while((temp=getchar())!='\n')
	{
		a[k++]=temp;
	}
	while((temp=getchar())!='\n')
	{
		mp[int(temp)]=1;
	}
	for(int i=0;i<k;i++)
	{
		if(mp[int(a[i])]==0)
			printf("%c",a[i]);
	}

	return 0;
}