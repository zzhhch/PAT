#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=50;

struct node
{
	int lchild,rchild;
}tree[maxn];
bool isRoot[maxn]={false};
int n,num=0;
int trs(char a)
{
	if(a=='-')
	{
		return -1;
	}	
	else
	{
		isRoot[a-'0']=true;
		return a-'0';
	}
}

int find(bool a[maxn])
{
	int i;
	for(i=0;i<maxn;i++)
	{
		if(a[i]==false)
			return i;
	}
}

void BFS(int root)
{
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		if(tree[top].lchild!=-1)
		{
			q.push(tree[top].lchild);
		}
		if(tree[top].rchild!=-1)
		{
			q.push(tree[top].rchild);
		}
		printf("%d",top);
		if(num<n-1)
			printf(" ");
		else
			printf("\n");
		num++;
	}
}

void inOrder(int root)
{
	if(root==-1)
		return;
	inOrder(tree[root].lchild);
	printf("%d",root);
	if(num<n-1)
		printf(" ");
	else
		printf("\n");
	num++;
	inOrder(tree[root].rchild);
}

void posOrder(int root)
{
	if(root==-1)
		return;
	posOrder(tree[root].lchild);
	posOrder(tree[root].rchild);
	swap(tree[root].lchild,tree[root].rchild);
}
int main()
{
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		char a,b;
		getchar();
		scanf("%c %c",&a,&b);
		
		tree[i].lchild=trs(a);
		tree[i].rchild=trs(b);
	}
	int root=find(isRoot);
	posOrder(root);
	BFS(root);
	num=0;
	inOrder(root);
	return 0;
}