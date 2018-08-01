#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student
{
	char id[8],name[10];
	int score;
}ss[100010];

bool cmp_1(Student a,Student b)
{
	return strcmp(a.id,b.id)<0;
}

bool cmp_2(Student a,Student b)
{
	if(strcmp(a.name,b.name)!=0)
		return strcmp(a.name,b.name)<0;
	else
		return strcmp(a.id,b.id)<0;
}

bool cmp_3(Student a,Student b)
{
	if(a.score!=b.score)
		return a.score<b.score;
	else
		return strcmp(a.id,b.id)<0;
}

int main()
{
	int n,c;
	scanf("%d %d",&n,&c);
	for(int i=0;i<n;i++)
	{
		scanf("%s %s %d",ss[i].id,ss[i].name,&ss[i].score);
	}
	if(c==1)
	{
		sort(ss,ss+n,cmp_1);
	}
	else if(c==2)
	{
		sort(ss,ss+n,cmp_2);
	}
	else if(c==3)
	{
		sort(ss,ss+n,cmp_3);
	}

	for(int i=0;i<n;i++)
	{
		printf("%s %s %d\n",ss[i].id,ss[i].name,ss[i].score);
	}

	return 0;
}