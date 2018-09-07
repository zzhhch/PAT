#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100010;

vector<int> node[maxn];
int n,maxDepth=0,num=0;
double p,r,sum=0.0;

void DFS(int index,int depth)
{
	if(node[index].size()==0)
	{
		if(depth>maxDepth)
		{
			maxDepth=depth;
			num=1;
		}
		else if(depth==maxDepth)
		{
			num++;
		}
		return;
	}
	for(int i=0;i<node[index].size();i++)
	{
		DFS(node[index][i],depth+1);
	}
}

int main()
{
	scanf("%d%lf%lf",&n,&p,&r);
	r=r/100;
	int father,root;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&father);
		if(father!=-1)
		{
			node[father].push_back(i);
		}
		else
		{
			root=i;
		}
	}
	DFS(root,0);
	printf("%.2lf %d\n",p*pow(1+r,maxDepth),num);
	return 0;
}