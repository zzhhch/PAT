#include<cstdio>
#include<cstring>

int ans[10]={0};
int main()
{
	char a[10010];
	int num=0;
	scanf("%s",a);
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]=='P')
		{
			num++;
			ans[0]++;
		}
		if(a[i]=='A')
		{
			num++;
			ans[1]++;
		}
		if(a[i]=='T')
		{
			num++;
			ans[2]++;
		}
		if(a[i]=='e')
		{
			num++;
			ans[3]++;
		}
		if(a[i]=='s')
		{
			num++;
			ans[4]++;
		}
		if(a[i]=='t')
		{
			num++;
			ans[5]++;
		}
	}
	//printf("%d\n",num);
	//for(int i=0;i<7;i++)
	//	printf("%d",ans[i]);
	while(num)
	{
		if(ans[0]>0)
		{
			printf("P");
			num--;
			ans[0]--;
		}
		if(ans[1]>0)
		{
			printf("A");
			num--;
			ans[1]--;
		}
		if(ans[2]>0)
		{
			printf("T");
			num--;
			ans[2]--;
		}
		if(ans[3]>0)
		{
			printf("e");
			num--;
			ans[3]--;
		}
		if(ans[4]>0)
		{
			printf("s");
			num--;
			ans[4]--;
		}
		if(ans[5]>0)
		{
			printf("t");
			num--;
			ans[5]--;
		}
	}

	return 0;
}