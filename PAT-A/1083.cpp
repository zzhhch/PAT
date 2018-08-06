#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student
{
	char name[15],id[15];
	int grade;
}ss[10010];

bool cmp(Student a,Student b)
{
	return a.grade>b.grade;
}

int main()
{
	int n,a,b,count=0;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		scanf("%s %s %d",ss[i].name,ss[i].id,&ss[i].grade);
	}
	sort(ss,ss+n,cmp);

	scanf("%d %d",&a,&b);
	for(int i=0;i<n;i++)
	{
		if(ss[i].grade<=b&&ss[i].grade>=a)
		{
			printf("%s %s\n",ss[i].name,ss[i].id);
			count++;
		}	
		if(ss[i].grade<a)
			break;	
	}
	if(count==0)
		printf("NONE\n");
	return 0;
}