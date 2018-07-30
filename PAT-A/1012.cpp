#include<cstdio>
#include<algorithm>
using namespace std;

struct Student
{
	int id,C,M,E,A,ar,cr,mr,er;
}ss[2010];
struct Rank
{
	int a;
	char b;
}aPrint;

/*
从中选取排名最高的 按A C M E 的优先级
*/
Rank maxRank(Student a)
{
	Rank best;
	best.a=a.ar;
	best.b='A';
	if(best.a>a.cr)
	{
		best.a=a.cr;
		best.b='C';
	}
	if(best.a>a.mr)
	{
		best.a=a.mr;
		best.b='M';
	}
	if(best.a>a.er)
	{
		best.a=a.er;
		best.b='E';
	}
	return best;
}

bool cmp1(Student a,Student b)
{
	return a.A>b.A;
}
bool cmp2(Student a,Student b)
{
	return a.C>b.C;
}
bool cmp3(Student a,Student b)
{
	return a.M>b.M;
}
bool cmp4(Student a,Student b)
{
	return a.E>b.E;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&ss[i].id,&ss[i].C,&ss[i].M,&ss[i].E);
		ss[i].A=(ss[i].C+ss[i].M+ss[i].E)/3;
	}
	/*
	进行4次排序，给每次排序加上名次
	*/
	sort(ss,ss+n,cmp1);
	ss[0].ar=1;
	for(int i=1;i<n;i++)
	{
		if(ss[i].A==ss[i-1].A)
			ss[i].ar=ss[i-1].ar;
		else
			ss[i].ar=i+1;
	}
	sort(ss,ss+n,cmp2);
	ss[0].cr=1;
	for(int i=1;i<n;i++)
	{
		if(ss[i].C==ss[i-1].C)
			ss[i].cr=ss[i-1].cr;
		else
			ss[i].cr=i+1;
	}
	sort(ss,ss+n,cmp3);
	ss[0].mr=1;
	for(int i=1;i<n;i++)
	{
		if(ss[i].M==ss[i-1].M)
			ss[i].mr=ss[i-1].mr;
		else
			ss[i].mr=i+1;
	}
	sort(ss,ss+n,cmp4);
	ss[0].er=1;
	for(int i=1;i<n;i++)
	{
		if(ss[i].E==ss[i-1].E)
			ss[i].er=ss[i-1].er;
		else
			ss[i].er=i+1;
	}
	for(int i=0;i<m;i++)
	{
		int k,j;
		scanf("%d",&k);
		for(j=0;j<n;j++)
		{
			if(k==ss[j].id)
			{
				Rank min=bestRank(ss[j]);
				printf("%d %c\n",min.a,min.b);
				break;
			}
		}
		if(j==n)
			printf("N/A\n");
	}
}