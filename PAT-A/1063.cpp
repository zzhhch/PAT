#include<cstdio>
#include<set>
using namespace std;

const int maxn=55;
set<int> ss[maxn];

void compare(int x,int y)
{
	int total=ss[y].size(),same=0;
	for(set<int>::iterator it=ss[x].begin();it!=ss[x].end();it++)
	{
		if(ss[y].find(*it)!=ss[y].end())
			same++;
		else
			total++;
	}
	printf("%.1f%%\n",same*100.0/total);
}
int main()
{
	int n,k,a,b,a1,b1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		for(int j=0;j<a;j++)
		{
			scanf("%d",&b);
			ss[i].insert(b);
		}
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&a1,&b1);
		compare(a1,b1);
	}
	return 0;
}