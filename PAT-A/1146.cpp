#include<cstdio>
#include<vector>
using namespace std;
const int MAXV=1010;

int G[MAXV][MAXV]={0};
vector<int> ans;
int n,m,a,b,k,temp;
bool isFrist(int a)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(G[i][a]!=0)
			return false;
	}
	return true;
}

int main()
{
	
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		G[a][b]=1;
	}
	scanf("%d",&k);
	printf("%d\n",k);
	for(int i=0;i<k;i++)
	{
		bool flag=true;
		for(int j=0;j<n;j++)
		{
			scanf("%d",&temp);
			if(isFrist(temp))
			{
				for(int x=0;x<n;x++)
				{
					if(G[temp][x]!=0)
						G[temp][x]=0;
					
				}
			}
			else
			{
				flag=false;
			}
		}
		if(flag)
		{
			ans.push_back(i);
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		printf("%d",ans[i]);
		if(i!=ans.size()-1)
			printf(" ");
	}
	return 0;
}