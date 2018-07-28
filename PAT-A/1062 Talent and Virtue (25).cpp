#include<cstdio>

struct pepole
{
	long id;
	int  virtue;
	int  talent;
	int  sum;
	int  flag;
}pp[100010],temp;
int main()
{
	int n,l,h,k=0;
	scanf("%d%d%d",&n,&l,&h);

	for(int i=0;i<n+1;i++)
	{
		long a;
		int b,c;
		scanf("%ld%d%d",&a,&b,&c);
		if(b>=60&&c>=60)
		{
			pp[k].id=a;
			pp[k].virtue=b;
			pp[k].talent=c;
			pp[k].sum=b+c;
			k++;
		}
	}
	for(int i=0;i<k-1;i++)
	{
		for(int j=i+1;j<k;j++)
		{
			if(pp[i].sum<pp[j].sum)
			{
				temp=pp[i];
				pp[i]=pp[j];
				pp[j]=temp;
			}
			else if(pp[i].sum==pp[j].sum&&pp[i].virtue<pp[j].virtue)
			{
				temp=pp[i];
				pp[i]=pp[j];
				pp[j]=temp;
			}
			else if(pp[i].sum==pp[j].sum&&pp[i].virtue==pp[j].virtue&&pp[i].id<pp[j].id)
			{
				temp=pp[i];
				pp[i]=pp[j];
				pp[j]=temp;
			}
		}
		if(pp[i].virtue>=h&&pp[i].talent>=h)
		{
			pp[i].flag=1;
		}
		else if(pp[i].virtue>=h&&pp[i].talent<h)
		{
			pp[i].flag=2;
		}
		else if(pp[i].virtue<h&&pp[i].talent<=pp[i].virtue)
		{
			pp[i].flag=3;
			printf("%ld %d %d\n",pp[i].id,pp[i].virtue,pp[i].talent);
		}
		else if(pp[i].virtue<h&&pp[i].talent>pp[i].virtue)
		{
			pp[i].flag=4;
		}
		else
			pp[i].flag=0;
	}
	printf("%d\n",k);
	for(int i=0;i<k;i++)
	{
		if(pp[i].flag==1)
			printf("%ld %d %d\n",pp[i].id,pp[i].virtue,pp[i].talent);
	}
	for(int i=0;i<k;i++)
	{
		if(pp[i].flag==2)
			printf("%ld %d %d\n",pp[i].id,pp[i].virtue,pp[i].talent);
	}
	for(int i=0;i<k;i++)
	{
		if(pp[i].flag==3)
			printf("%ld %d %d\n",pp[i].id,pp[i].virtue,pp[i].talent);
	}
	for(int i=0;i<k;i++)
	{
		if(pp[i].flag==4)
			printf("%ld %d %d\n",pp[i].id,pp[i].virtue,pp[i].talent);
	}

	return 0;
}