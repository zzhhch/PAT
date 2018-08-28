#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn=40010;
const int maxc=2510;
char name[maxn][5];
vector<int> ss[maxc];

bool cmp(int a,int b)
{
	return strcmp(name[a],name[b])<0;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		int b;
		scanf("%s %d",name[i],&b);
		for(int j=0;j<b;j++)
		{
			int id;
			scanf("%d",&id);
			ss[id].push_back(i);
		}
	}
	for(int i=1;i<=k;i++)
	{
		sort(ss[i].begin(),ss[i].end(),cmp);
		printf("%d %d\n",i,ss[i].size());
		for(int j=0;j<ss[i].size();j++)
		{
			printf("%s\n",name[ss[i][j]]);;
		}
	}
	return 0;

}