#include<cstdio>

const int maxn=100010;
struct Node
{
	int date,next;	
}node[maxn];

int main()
{
	int head,n,k;
	scanf("%d%d%d",&head,&n,&k);
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		node[a].date=b;
		node[a].next=c;
	}
	int nowk=1,p=node[head].next,q,r=head;
	if(p!=-1)
	{
		while(nowk<k&&q!=-1)
		{
			q=node[p].next;
			node[p].next=r;
			r=p;
			p=q;
			nowk++;
		}
		node[head].next=p;
		head=r;
	}
	
	while(node[r].next!=-1)
	{
		printf("%05d %d %05d\n",r,node[r].date,node[r].next);
		r=node[r].next;
	}
	printf("%05d %d %d\n",r,node[r].date,node[r].next);

	return 0;
}