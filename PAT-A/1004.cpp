#include<cstdio>
#include<vector>
using namespace std;
const int maxn=110;

vector<int> child[maxn];
bool isRoot[maxn]={false};
bool isNode[maxn]={false};
int leaf[maxn]={0};
int n,m,maxDepth=0;

int findRoot()
{
	int i;
	for(i=0;i<maxn;i++)
	{
		if(isNode[i]==true&&isRoot[i]==false)
		{
			return i;
		}
	}
}

void DFS(int root,int depth)
{
	if(depth>maxDepth){
		maxDepth=depth;
	}
	if(child[root].size()==0){
		leaf[depth]++;
		return;
	}
	for(int i=0;i<child[root].size();i++){
		DFS(child[root][i],depth+1);
	}
}

int main()
{
	int now,num,ans;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&now,&num);
		isNode[now]=true;
		for(int j=0;j<num;j++)
		{
			scanf("%d",&ans);
			isRoot[ans]=true;
			isNode[ans]=true;
			child[now].push_back(ans);
		}
	}
	int root=findRoot();
	DFS(root,0);
	for(int i=0;i<=maxDepth;i++){
		printf("%d",leaf[i]);
		if(i<maxDepth){
			printf(" ");
		}
	}
	return 0;
}