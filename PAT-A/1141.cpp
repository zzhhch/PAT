#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100010;

struct Node
{
	int num=0;
	double score=0;
	char school[8];
}node[maxn];

int hash(char a[])
{
	int ans=0;
	for(int i=0;i<8;i++)
	{
		if(a[i]!='\0')
			ans+=26*(a[i]-'a');
		else
			break;
	}
	return ans%100001;
}

bool cmp(Node a,Node b)
{
	if(a.score!=b.score)
		return a.score>b.score;
	else if(a.num!=b.num)
		return a.num<b.num;
	else
		return strcmp(a.school,b.school)<0;
}

int main()
{
	int n,score,count=0;
	scanf("%d",&n);
	char id[8],sc[8];
	for(int i=0;i<n;i++)
	{
		scanf("%s %d %s",id,&score,sc);
		for(int j=0;j<8;j++)
		{
			if(sc[j]>='A'&&sc[j]<='Z')
				sc[j]=sc[j]+32;
		}
		int ID=hash(sc);
		if(node[ID].num==0)
		{
			strcpy(node[ID].school,sc);
			count++;
		}
		if(id[0]=='B')
		{
			node[ID].score+=score/1.5;
			node[ID].num++;
		}
		else if(id[0]=='A')
		{
			node[ID].score+=score;
			node[ID].num++;
		}
		else
		{
			node[ID].score+=score*1.5;
			node[ID].num++;
		}
	}
	sort(node,node+maxn,cmp);
	int Rank=1;
	printf("%d\n%d %s %d %d\n",count,Rank,node[0].school,int(node[0].score),node[0].num);
	for(int i=1;i<count;i++)
	{
		if(node[i].score==node[i-1].score)
			printf("%d %s %d %d\n",Rank,node[i].school,int(node[i].score),node[i].num);
		else
		{
			printf("%d %s %d %d\n",i+1,node[i].school,int(node[i].score),node[i].num);
			Rank=i+1;
		}	
	}
	return 0;
}