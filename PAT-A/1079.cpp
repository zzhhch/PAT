#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=100010;

struct node
{
	int data;
	vector<int> child;
}tree[maxn];
double sum=0,P,r;

void BFS(int root,int depth)
{
	if(tree[root].child.size()==0)
	{
		sum+=tree[root].data*P*(pow(1+r/100,depth));
	}
	else
	{
		for(int i=0;i<tree[root].child.size();i++)
		{
			BFS(tree[root].child[i],depth+1);
		}
	}
}

int main()
{
	int n;
	scanf("%d%lf%lf",&n,&P,&r);
	for(int i=0;i<n;i++)
	{
		int temp,x;
		scanf("%d",&temp);
		if(temp==0)
		{
			scanf("%d",&tree[i].data);
		}
		else
		{
			for(int j=0;j<temp;j++)
			{
				scanf("%d",&x);
				tree[i].child.push_back(x);
			}
		}
	}
	BFS(0,0);
	printf("%.1f\n",sum);
	return 0;
}

/*有2个测试点超时

#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=100010;

struct node
{
	int num=0,layer;
	vector<int> child;
}tree[maxn];

void level_order(int root)
{
	queue<int> q;
	tree[root].layer=0;
	q.push(root);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=0;i<tree[now].child.size();i++)
		{
			tree[tree[now].child[i]].layer=tree[now].layer+1;
			q.push(tree[now].child[i]);
		}
	}
}

bool cmp(node a,node b)
{
	if(a.child.size()!=b.child.size())
		return a.child.size()<b.child.size();
	return a.layer<b.layer;
}

double power(double a,double b)
{
	double m=1;
	for(int i=0;i<b;i++)
		m=m*(1+a/100);
	return m;
}
int main()
{
	int n;
	double P,r;
	scanf("%d%lf%lf",&n,&P,&r);
	for(int i=0;i<n;i++)
	{
		int temp,ans;
		scanf("%d",&temp);
		if(temp==0)
		{
			scanf("%d",&tree[i].num);
		}
		else
		{
			for(int j=0;j<temp;j++)
			{
				scanf("%d",&ans);
				tree[i].child.push_back(ans);
			}
		}
	}
	level_order(0);
	sort(tree,tree+n,cmp);
	double sum=0;
	for(int i=0;i<n;i++)
	{
		if(tree[i].child.size()!=0)
			break;
		sum+=tree[i].num*P*(power(r,tree[i].layer));
	}
	printf("%.1f\n",sum);

	return 0;
}

*/