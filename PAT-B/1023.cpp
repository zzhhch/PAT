#include<cstdio>

int mp[15]={0};
int main()
{
	for(int i=0;i<10;i++)
		scanf("%d",&mp[i]);
	for(int i=1;i<10;i++)
	{
		if(mp[i]!=0)
		{
			printf("%d",i);
			mp[i]--;
			break;
		}
	}
	for(int i=0;i<10;i++)
	{
		while(mp[i]--)
		{
			printf("%d",i);
		}
	}

	return 0;
		
}