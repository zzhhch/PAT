#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1010;

struct Weight
{
	int weight;
	int rank;
}we[maxn];

int main()
{
	int np,ng,order;
	queue<int> q;
	scanf("%d%d",&np,&ng);
	for(int i=0;i<np;i++)
	{
		scanf("%d",&we[i].weight);
	}
	for(int i=0;i<np;i++)
	{
		scanf("%d",&order);
		q.push(order);
	}
	int temp=np,group;
	while(q.size()!=1)
	{
		if(temp%ng==0)
			group=temp/ng;
		else
			group=temp/ng+1;
		for(int i=0;i<group;i++)
		{
			int k=q.front();
			for(int j=0;j<ng;j++)
			{
				if(i*ng+j>=temp)
				{
					break;
				}
				int front=q.front();
				if(we[front].weight>we[k].weight)
				{
					k=front;
				}
				we[front].rank=group+1;
				q.pop();
			}
			q.push(k);
		}
		temp=group;	
	}
	we[q.front()].rank=1;
		for(int i=0;i<np;i++)
		{
			printf("%d",we[i].rank);
			if(i<np-1)
				printf(" ");
		}
	return 0;
}