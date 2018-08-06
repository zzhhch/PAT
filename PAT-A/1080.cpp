#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int mp[110];//每个学校的容量

struct Student
{
	int Ge,Gi,sum,choices[10],id,ac=101;
}ss[40010];//记录学生的分数和选择

/*
比较学生的总分和Ge
*/
bool cmp(Student a,Student b)
{
	if(a.sum!=b.sum)
		return a.sum>b.sum;
	else
		return a.Ge>b.Ge;
}

//用录取学校进行排序
bool cmp1(Student a,Student b)
{
	if(a.ac!=b.ac)
		return a.ac<b.ac;
	else
		return a.id<b.id;
}

int main()
{
	int n,m,k;//申请数量，学校数，每个人的选择数量
	scanf("%d %d %d",&n,&m,&k);

	for(int i=0;i<m;i++)
	{
		scanf("%d",&mp[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&ss[i].Ge,&ss[i].Gi);
		ss[i].sum=ss[i].Ge+ss[i].Gi;
		ss[i].id=i;
		for(int j=0;j<k;j++)
			scanf("%d",&ss[i].choices[j]);
	}
	sort(ss,ss+n,cmp);
	/*for(int i=0;i<n;i++)
	{
		printf("%d %d \n",ss[i].id,ss[i].sum);
	}	
	*/
	ss[0].ac=ss[0].choices[0];
	mp[ss[0].choices[0]]--;
	for(int i=1;i<n;i++)
	{
		if(ss[i].sum==ss[i-1].sum&&ss[i].Ge==ss[i-1].Ge&&ss[i].Gi==ss[i-1].Gi)
		{
			for(int j=0;j<k;j++)
			{
				if(mp[ss[i].choices[j]]!=0)
				{
					mp[ss[i].choices[j]]--;
					ss[i].ac=ss[i].choices[j];
					break;
				}
			}
			if(ss[i].ac==101)
			{
				ss[i].ac=ss[i-1].ac;
			}
		}
		else
		{
			for(int j=0;j<k;j++)
			{
				if(mp[ss[i].choices[j]]!=0)
				{
					mp[ss[i].choices[j]]--;
					ss[i].ac=ss[i].choices[j];
					break;
				}
			}
		}	
	}
	sort(ss,ss+n,cmp1);
	//for(int i=0;i<n;i++)
	//	printf("%d %d\n",ss[i].id,ss[i].ac);
	int count=0;
	for(int i=0;i<m;i++)
	{
		if(ss[count].ac>100)
			break;
		while(ss[count].ac==i)
		{
			
			if(ss[count].ac>100)
				break;
			if(ss[count]!=101)
			{
				printf("%d ",ss[count].id);
			}
			else
			{
				printf("%d",ss[count].id);
			}
			count++;
		}
		printf("\n");
	}

	return 0;
}