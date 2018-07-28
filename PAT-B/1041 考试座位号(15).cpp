#include<stdio.h>
//可以用数组下标做为试机的座位号
struct Stu
{
	long long id;
	int test_id;
	int exam_id;
}stu[1010];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld %d %d",&stu[i].id,&stu[i].test_id,&stu[i].exam_id);
	}

	int m,temp;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&temp);
		for(int j=0;j<n;j++)
		{
			if(temp==stu[j].test_id)
				printf("%lld %d\n",stu[j].id,stu[j].exam_id);
		}
	}

	return 0;
}
