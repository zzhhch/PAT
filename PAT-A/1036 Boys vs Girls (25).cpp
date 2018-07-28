#include<cstdio>
struct Student
{
	char name[11];
	char sex;
	char ID[11];
	int score;
}highest_F,lowest_M,Input;

int main()
{
	int n;
	scanf("%d",&n);
	highest_F.score=-1;
	lowest_M.score=101;
	while(n--)
	{
		scanf("%s %c %s %d",Input.name,&Input.sex,Input.ID,&Input.score);
		if(Input.sex=='F'&&Input.score>highest_F.score)
			highest_F=Input;
		if(Input.sex=='M'&&Input.score<lowest_M.score)
			lowest_M=Input;
	}
	if(highest_F.score!=-1)
		printf("%s %s\n",highest_F.name,highest_F.ID);
	else
		printf("Absent\n");
	if(lowest_M.score!=101)
		printf("%s %s\n",lowest_M.name,lowest_M.ID);
	else
		printf("Absent\n");
	if(highest_F.score!=-1&&lowest_M.score!=101)
		printf("%d\n",highest_F.score-lowest_M.score);
	else
		printf("NA\n");

	return 0;
}