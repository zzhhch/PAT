#include<cstdio>
#include<algorithm>
using namespace std;
struct Student
{
	int id,score[6]={-1,-1,-1,-1,-1,-1},rank,sum,full_mask;
	bool isPrint=false;
}ss[10010];
int mp[6]={0};

bool cmp(Student a,Student b)
{
	if(a.isPrint!=b.isPrint)
		return a.isPrint>b.isPrint;
	else if(a.sum!=b.sum)
		return a.sum>b.sum;
	else if(a.full_mask!=b.full_mask)
		return a.full_mask>b.full_mask;
	else
		return a.id<b.id;
}

int main()
{
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&mp[i]);
	}
	int a,b,c;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(ss[a].id==0)
			ss[a].id=a;
		if(c>=0&&c>=ss[a].score[b-1])
		{
			ss[a].isPrint=true;
			if(ss[a].score[b-1]==-1)
			{
				ss[a].sum+=c;
				ss[a].score[b-1]=c;
			}	
			else
			{
				ss[a].sum+=c-ss[a].score[b-1];
				ss[a].score[b-1]=c;
			}	
			if(c==mp[b-1])
				ss[a].full_mask++;
		}
		else if(c==-1&&ss[a].score[b-1]==-1)
		{
			ss[a].score[b-1]=0;
		}	
	}
	sort(ss,ss+10010,cmp);
	//for(int i=0;i<n;i++)
		//printf("%d",ss[i].isPrint);

	if(ss[0].isPrint)
	{
		int count=1;
		printf("%d %05d %d",count,ss[0].id,ss[0].sum);
		for(int i=0;i<k;i++)
		{
			if(ss[0].score[i]==-1)
				printf(" -");
			else
				printf(" %d",ss[0].score[i]);
		}
		printf("\n");
		for(int i=1;i<=n;i++)
		{
			if(ss[i].isPrint)
			{
				if(ss[i].sum==ss[i-1].sum)
				{
					printf("%d %05d %d",count,ss[i].id,ss[i].sum);
				}
				else
				{
					printf("%d %05d %d",i+1,ss[i].id,ss[i].sum);
					count=i+1;
				}	
				for(int j=0;j<k;j++)
				{
					if(ss[i].score[j]==-1)
						printf(" -");
					else
						printf(" %d",ss[i].score[j]);
				}
				printf("\n");
			}
			else
				break;
		}
	}
	
	return 0;
}