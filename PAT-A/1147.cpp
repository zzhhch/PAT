#include<cstdio>
const int maxn=1010;
struct node
{
	int data;
	node* lchild;
	node* rchild;
};
bool isHeap,isMheap;
int n,m;
int level[maxn],post[maxn];

node creat(int a[])
{
	node* root;
	node* p=root;
	for(int i=1;i<=m;i++)
	{
		if(2*i<=m)
		{
			if(2*i+1<=m)		
			{

			}
		}
		else
		

	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		isHeap=true;
		isMheap=true;
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&level[j]);
			if(!Isheap)
			{
				isHeap=false;
			}
			if(level[1]<level[2])
			{
				isMheap=false;
			}
			node root=creat(level);
		}
	}
}