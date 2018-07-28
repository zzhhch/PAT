#include<stdio.h>

struct student
{
	char name[15];
	char id[15];
	int  score;
}stu[1000];

int main()
{
	int n,i,Max=0,Min=0;

	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%s",stu[i].name);
		scanf("%s",stu[i].id);
		scanf("%d",&stu[i].score);

		if(stu[i].score>stu[Max].score)
			Max=i;
		if(stu[i].score<stu[Min].score)
			Min=i;
	}

	printf("%s %s\n",stu[Max].name,stu[Max].id);
	printf("%s %s\n",stu[Min].name,stu[Min].id);

	return 0;
}