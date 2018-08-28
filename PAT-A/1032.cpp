#include<cstdio>

struct Node
{
	char date;
	int next;
	bool flag;
}node[100010];

int main()
{
	int L1,L2,n;
	for(int i=0;i<100010;i++)
	{
		node[i].flag=false;
	}
	scanf("%d%d%d",&L1,&L2,&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		scanf(" %c%d",&node[a].date,&node[a].next);
	}
	int p;
	for(p=L1;p!=-1;p=node[p].next)
	{
		node[p].flag=true;
	}
	for(p=L2;p!=-1;p=node[p].next)
	{
		if(node[p].flag==true)
			break;
	}
	
	if(p==-1)
		printf("-1\n");
	else
		printf("%05d\n",p);
	return 0;
}