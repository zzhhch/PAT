#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn=26*26*26*10+1;

struct Student
{
	vector<int> course;
}ss[maxn];

int getID(char a[])
{
	int id=0;
	for(int i=0;i<3;i++)
	{
		id=id*26+(a[i]-'A');
	}
	id=id*10+(a[3]-'0');

	return id;
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int j=0;j<b;j++)
		{
			char name[5];
			scanf("%s",name);
			ss[getID(name)].course.push_back(a);
		}
	}
	for(int i=0;i<n;i++)
	{
		char name[5];
		scanf("%s",name);
		int ans=getID(name);
		sort(ss[ans].course.begin(),ss[ans].course.end());
		printf("%s %d",name,ss[ans].course.size());
		for(int j=0;j<ss[ans].course.size();j++)
		{
			printf(" %d",ss[ans].course[j]);
		}
		printf("\n");
	}
	return 0;
}