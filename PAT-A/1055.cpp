#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct People
{
	char name[10];
	int age,worth;
}pp[100010],ps[100010];

int Age[100010]={0};

bool cmp(People a,People b)
{
	if(a.worth!=b.worth)
		return a.worth>b.worth;
	else if(a.age!=b.age)
		return a.age<b.age;
	else
		return strcmp(a.name,b.name)<0;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++)
	{
		scanf("%s %d %d",pp[i].name,&pp[i].age,&pp[i].worth);
	}
	sort(pp,pp+n,cmp);
	int valid=0;
	for(int i=0;i<n;i++)
	{
		if(Age[pp[i].age]<100)
		{
			Age[pp[i].age]++;
			ps[valid++]=pp[i];
		}
	}

	int num,min,max,count;
	for(int i=1;i<=m;i++)
	{
		num=0;
		scanf("%d %d %d",&count,&min,&max);
		printf("Case #%d:\n",i);
		for(int j=0;j<valid;j++)
		{
			if(ps[j].age>=min&&ps[j].age<=max)
			{
				printf("%s %d %d\n",ps[j].name,ps[j].age,ps[j].worth);
				num++;
			}
			if(num==count)
				break;
		}
		if(num==0)
			printf("None\n");
	}

	return 0;

}