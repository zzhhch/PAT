#include<cstdio>
#include<algorithm>
using namespace std;
int mp[100000]={0};

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int n,num[110],a;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		num[i]=a;
		while(a!=1)
		{
			if(a%2==0)
				a/=2;
			else
				a=(3*a+1)/2;
			mp[a]=1;
		}
	}
	sort(num,num+n,cmp);
	bool tcase=true;
	for(int i=0;i<n;i++)
	{
		if(mp[num[i]]==0)
		{
			if(tcase)
			{
				tcase=false;
				printf("%d",num[i]);
			}
			else
				printf(" %d",num[i]);	
		}	
	}

	return 0;
}