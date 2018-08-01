#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student
{
	char id[15];
	int score,local,local_rank;
}ss[30010];

bool cmp(Student a,Student b)
{
	if(a.score!=b.score)
		return a.score>b.score;
	else
		return strcmp(a.id,b.id)<0;
}

int main()
{
	int n,sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			scanf("%s %d",ss[sum].id,&ss[sum].score);
			ss[sum].local=i+1;
			sum++;
		}
		sort(ss+sum-k,ss+sum,cmp);
		ss[sum-k].local_rank=1;
		for(int j=2;j<=k;j++)
		{
			if(ss[sum-k+j-1].score==ss[sum-k+j-2].score)
				ss[sum-k+j-1].local_rank=ss[sum-k+j-2].local_rank;
			else
				ss[sum-k+j-1].local_rank=j;
		}
	}
	printf("%d\n",sum);
	sort(ss,ss+sum,cmp);
	int rank=1;
	printf("%s %d %d %d\n",ss[0].id,rank,ss[0].local,ss[0].local_rank);
	for(int i=1;i<sum;i++)
	{
		if(ss[i].score==ss[i-1].score)
			printf("%s %d %d %d\n",ss[i].id,rank,ss[i].local,ss[i].local_rank);
		else
		{
			printf("%s %d %d %d\n",ss[i].id,i+1,ss[i].local,ss[i].local_rank);
			rank=i+1;
		}	
	}

	return 0;
}