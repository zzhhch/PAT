#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100010;

bool cmp(long a,long b)
{
	return a<b;
}

int main()
{
	long n,p,num[maxn];
	scanf("%ld%ld",&n,&p);
	for(int i=0;i<n;i++)
	{
		scanf("%ld",&num[i]);
	}
	sort(num,num+n,cmp);
	int i=0,j=n-1;
	while(i<j)
	{
		if(num[i]*p>=num[j])
			break;
		else
		{
			if(num[i+1]*p>=num[j]||num[i]*p>=num[j-1])
			{
				n--;
				break;
			}
			else
			{
				i++;
				j--;
				n-=2;
			}
		}
	}

	printf("%ld\n",n);

	return 0;
}