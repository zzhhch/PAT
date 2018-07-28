#include<stdio.h>
//书上用的一个struct存最早时间另一个最晚，分开读入时间
struct data
{
	char id[15];
	int hh1,mm1,ss1,hh2,mm2,ss2;
}now,earlest,latest;

bool Isearly(data a,data b)
{
	if(a.hh1<b.hh1)
		return true;
	else if(a.hh1==b.hh1&&a.mm1<b.mm1)
		return true;
	else if(a.hh1==b.hh1&&a.mm1==b.mm1&&a.ss1<b.ss1)
		return true;
	else
		return false;
}
bool Islate(data a,data b)
{
	if(a.hh2>b.hh2)
		return true;
	else if(a.hh2==b.hh2&&a.mm2>b.mm2)
		return true;
	else if(a.hh2==b.hh2&&a.mm2==b.mm2&&a.ss2>b.ss2)
		return true;
	else
		return false;
}
int main()
{
	earlest.hh1=24;
	earlest.mm1=59;
	earlest.ss1=59;
	latest.hh2=0;
	latest.mm2=0;
	latest.ss2=0;

	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s %d:%d:%d %d:%d:%d",now.id,&now.hh1,&now.mm1,&now.ss1,&now.hh2,&now.mm2,&now.ss2);
		if(Isearly(now,earlest))
			earlest=now;
		if(Islate(now,latest))
			latest=now;
	}

	printf("%s %s",earlest.id,latest.id);

	return 0;
}
