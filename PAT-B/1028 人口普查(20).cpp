#include<stdio.h>

struct People
{
	char name[6];
	int yy;
	int mm;
	int dd;
}pp[100010],max,min;

bool Islegal(People a)
{
	if(a.yy<2014&&a.yy>1814)
		return true;
	else if((a.yy==2014&&a.mm<9)||(a.yy==1814&&a.mm>9))
		return true;
	else if((a.yy==2014&&a.mm==9&&a.dd<=6)||(a.yy==1814&&a.mm==9&&a.dd>=6))
		return true;
	else
		return false;
}
bool Ismore(People a,People b)
{
	if(a.yy<b.yy)
		return true;
	else if((a.yy==b.yy)&&(a.mm<b.mm))
		return true;
	else if((a.yy==b.yy)&&(a.mm==b.mm)&&(a.dd<b.dd))
		return true;
	else
		return false;
}

int main()
{
	int n,minn,maxn,count=0;
	scanf("%d",&n);
	max.yy=1814;
	min.yy=2014;
	max.mm=min.mm=9;
	max.dd=min.dd=6;

	for(int i=0;i<n;i++)
	{
		scanf("%s %d/%d/%d",pp[i].name,&pp[i].yy,&pp[i].mm,&pp[i].dd);
		if(Islegal(pp[i]))
		{
			count++;
			if(Ismore(pp[i],max))
				{
					maxn=i;
					max=pp[i];
				}			
			if(Ismore(min,pp[i]))
				{
					minn=i;
					min=pp[i];
				}
		}
	}
	if(count==0)
		printf("0\n");
	else
		printf("%d %s %s\n",count,pp[maxn].name,pp[minn].name);

	return 0;
}
