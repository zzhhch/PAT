#include<cstdio>
#include<cstring>

bool isBreak[130]={false};

int main()
{
	char broken[45],input[100010];

	if(getchar(broken[0])!='\n')
		{
			scanf("%s%s",broken+1,input);
		}
	else
		scanf("%s",input);
	int len1=strlen(broken),len2=strlen(input);
	//printf("%s  %s\n",broken,input);
	/*for (int i = 0; i < 130; ++i)
	{
		printf("%d ",isBreak[i]);
		if(i%10==0)
			printf("\n");
	}
	*/
	for(int i=0;i<len1;i++)
	{
		isBreak[broken[i]]=true;
	}



	for(int i=0;i<len2;i++)
	{
		char a;
		a=input[i];
		if(a-'a'>=0&&a-'z'<=0)
		{
			a=a-'a'+'A';
			if(!isBreak[a])
				printf("%c",a+32);
		}
		else if(a-'A'>=0&&a-'Z'<=0)
		{
			if(!isBreak[a]&&!isBreak['+'])
				printf("%c",a);
		}
		else if(isBreak[a]==false)
			printf("%c",a);
	}
	printf("\n");

	return 0;
}