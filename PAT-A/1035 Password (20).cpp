#include<cstdio>
#include<cstring>

struct pp{
	char id[20];
	char password[20];
}num[1010];

int main()
{
	int a[1010]={0};
	int n,k=0,len;
	bool tcase=false;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s %s",num[i].id,num[i].password);
	}
	for(int i=0;i<n;i++)
	{ 
		len=strlen(num[i].password);
		tcase=false;
		for(int j=0;j<len;j++)
		{
			if(num[i].password[j]=='1')
			{
				tcase=true;
				num[i].password[j]='@';
			}
			if(num[i].password[j]=='0')
			{
				tcase=true;
				num[i].password[j]='%';
			}
			if(num[i].password[j]=='l')
			{
				tcase=true;
				num[i].password[j]='L';
			}
			if(num[i].password[j]=='O')
			{
				tcase=true;
				num[i].password[j]='o';
			}
		}
		if(tcase)
		    a[k++]=i;
	}
	if(k==0)
	{
		if(n==1)
		    printf("There is %d account and no account is modified\n",n);
		else
			printf("There are %d accounts and no account is modified\n",n);
	}
	else
	{
		printf("%d\n",k);
		for(int i=0;i<k;i++)
		{
			printf("%s %s\n",num[a[i]].id,num[a[i]].password);
		}
	}

	return 0;
}
