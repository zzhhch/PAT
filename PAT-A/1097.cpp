#include<cstdio>
#include<algorithm>
#include<cstring>
using  namespace std;

const int maxn=100010;
const int Max=10010;
struct Node
{
	int address,data,next;
	int order;
}node[maxn];
bool isExist[Max]={0};
bool cmp(Node a,Node b)
{
	return a.order<b.order;
}
int main()
{
	memset(isExist,false,sizeof(isExist));
	for(int i=0;i<maxn;i++)
	{
		node[i].order=2*maxn;
	}
	int n,begin,address;
	scanf("%d%d",&begin,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&address);
		scanf("%d %d",&node[address].data,&node[address].next);
		node[address].address=address;
	}
	int countVaild=0,countRemove=0,p=begin;
	while(p!=-1)
	{
		if(!isExist[abs(node[p].data)])
		{
			isExist[abs(node[p].data)]=true;
			node[p].order=countVaild++;
		}
		else
		{
			node[p].order=maxn+countRemove++;
		}
		p=node[p].next;
	}
	sort(node,node+maxn,cmp);
	int count=countRemove+countVaild;
	for(int i=0;i<count;i++)
	{
		if(i!=count-1&&i!=countVaild-1)
		{
			printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
		}
		else
		{
			printf("%05d %d -1\n",node[i].address,node[i].data);
		}
	}
	return 0;
}