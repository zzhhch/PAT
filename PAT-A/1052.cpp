#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct Node
{
	int address,keys,next;
	bool flag;	
}node[maxn];

bool cmp(Node a,Node b)
{
	if(a.flag==false||b.flag==false)
		return a.flag>b.flag;
	else
		return a.keys<b.keys;
}

int main()
{
	for(int i=0;i<maxn;i++)
	{
		node[i].flag=false;
	}
	int n,head,temp;
	scanf("%d%d",&n,&head);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		scanf("%d%d",&node[temp].keys,&node[temp].next);
		node[temp].address=temp;
	}
	int count=0,p=head;
	while(p!=-1)
	{
		node[p].flag=true;
		count++;
		p=node[p].next;
	}
	if(count==0)
		printf("0 -1\n");
	else
	{
		sort(node,node+maxn,cmp);
		printf("%d %05d\n",count,node[0].address);
		for(int i=0;i<count;i++)
		{
			if(i!=count-1)
				printf("%05d %d %05d\n",node[i].address,node[i].keys,node[i+1].address);
			else
				printf("%05d %d -1\n",node[i].address,node[i].keys);
		}
	}
	return 0;
}